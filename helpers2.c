// Helper functions for music
// Still missing support for flat, in particular Ab, Bb, Eb
// I completely assigned the flat keys incorrectly in the array.
// It's not A#b0. It should be A#0 && Bb0
// I've corrected the array and it's now returning frequencies for all.
// I need to final test against calculations and run the check.

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
/* --
The frequencies of one octave’s notes differ from those of adjacent octaves'
notes by a factor of two. For instance, the frequency of A3 is 220 Hz (i.e., half that of A4),
while the frequency of A5 is 880 Hz (i.e., twice that of A4). More generally, the frequency, f,
of some note is 2n/12 × 440, where n is the number of semitones from that note to A4, where n is negative
if that note is below (i.e., to the left of) A4 and positive if that note is above (i.e., to the right of) A4.
-- */
    //create a multidemensional array to hold all 88 piano keys
    char keys[89][7] = {{0}};
    int key = 72;
    char k;
    char sharp = {0};
    char flat = 'b';
    int octave = 0;
    char note[4]= {0};
    note[0] = 'A';
    note[1] = 'b';
    note[2] = '5';
    int A4 = 48;
    // assign fraction to decimal variable
    double fracToDec = 0;
    // assign numerator variable (number of keys from A4);
    double n = 0;
    // assign denominator variable
    double d = 12;
    double frequencyFloat = 0;
    int ret;
    int ret1;
    int ret2;
    string noteString = note;
    string keyString = "";
    char keyStringSharp[1][4] = {{0}};
    char keyStringFlat[1][4] = {{0}};
    string kSSharp = "";
    string kSFlat = "";
    for(int i = 0; i < 88; i++)
    {
       // since octaves begin with C, assign ASCII index values for A and B as 72 and 73 for loop
       if(key == 72)
       {
       k = 'A';
       }
       else if (key == 73)
       {
           k = 'B';
       }
       else
       {
           k = key;
       }
       char k1 = k + 1;
       if (k1 == 72)
       {
           k1 = 'A';
       }
       // merge note letter and octive into one string.
       char mergedKey[7];
       if(sharp == '#')
       {
           //add support for b, saving 6 values to key instead of 3. 3 for sharp, 3 for flat
           sprintf(mergedKey, "%c%c%i%c%c%i", k, sharp, octave, k1, flat, octave);
           // sharp key
           keys[i][0] = mergedKey[0];
           keys[i][1] = mergedKey[1];
           keys[i][2] = mergedKey[2];
           // flat key
           keys[i][3] = mergedKey[3];
           keys[i][4] = mergedKey[4];
           keys[i][5] = mergedKey[5];
           // create sharp note string
           keyStringSharp[0][0] = keys[i][0];
           keyStringSharp[0][1] = keys[i][1];
           keyStringSharp[0][2] = keys[i][2];
           // create flat note string
           keyStringFlat[0][0] = keys[i][3];
           keyStringFlat[0][1] = keys[i][4];
           keyStringFlat[0][2] = keys[i][5];
           sharp = 0;
           if(key < 73)
           {
               key++;
           }
           else
           {
               key = 67;
           }
       }
       else
       {
           int thisKey = 0;
           sprintf(mergedKey, "%c%i", k, octave);
           keys[i][0] = mergedKey[0];
           keys[i][1] = mergedKey[1];
           switch(key)
           {
               case 73:
                    thisKey = 73;
                    key = 67;
                    sharp = 0;
                    break;
               case 69:
                    thisKey = 69;
                    key++;
                    sharp = 0;
                    break;
           }
           if(thisKey != 73 && key != 73 && thisKey != 69 && key != 69)
           {
               sharp = '#';
           }

       }

        if (key == 67 && sharp == 0)
        {
            octave++;
        }
        printf("%s ", keys[i]);
        keyString = keys[i];
        ret = strncmp(noteString, keyString, 3);
        if(sharp != '#' && key != 67 && key != 70)
        {
        kSSharp = keyStringSharp[0];
        kSFlat = keyStringFlat[0];
        ret1 = strncmp(noteString, kSSharp, 3);
        ret2 = strncmp(noteString, kSFlat, 3);
        }
        else
        {
            kSSharp = "";
            kSFlat = "";
            ret1 = 1;
            ret2 = 1;
        }
        if (ret == 0 || ret1 == 0 || ret2 == 0)
        {
            n = i - A4;
            fracToDec = n / d;
            frequencyFloat = pow(2.00,fracToDec) * 440;
            int f = round(frequencyFloat);
            printf("Answer: %i\n", f);
            // return 0;
        }
    }
    printf("\n");
    // int ret;
    string s = get_string("Enter String: ");
    ret = strncmp(s, "", 1);
    if (ret == 0)
    printf("true");
    else
    printf("false");
}