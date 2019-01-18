// Helper functions for music

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
    char keys[89][4] = {{0}};
    int key = 72;
    char k;
    char sharp = {0};
    int octave = 0;
    char note[3]= {0};
    note[0] = 'A';
    note[1] = '3';
    string noteString = note;
    int A4 = 48;
    // assign fraction to decimal variable
    double fracToDec = 0;
    // assign numerator variable (number of keys from A4);
    double n = 0;
    // assign denominator variable
    double d = 12;
    double frequencyFloat = 0;
    int ret;
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
       // merge note letter and octive into one string.
       char mergedKey[4];
       if(sharp == '#')
       {
           sprintf(mergedKey, "%c%c%i", k, sharp, octave);
           keys[i][0] = mergedKey[0];
           keys[i][1] = mergedKey[1];
           keys[i][2] = mergedKey[2];
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
        string keyString = keys[i];
        ret = strncmp(noteString, keyString, 3);
        if (ret == 0)
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