/*-- This program takes a password hash from command line, then generates
every possible 5 letter password combination using upper and lowercase
letters, then uses crypt() to hash the generated word, and finally compares the hash
to the user hash input from command line.  If they match, password has been cracked --*/
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// first, get hashed password from command line argument
int main(int argc, string argv[])
{
    // only accept a single command-line argument
    if (argc == 2)
    {
        // create an array (alpha[]) of all upper and lowercase letters
        char alpha[53];
        char c;
        // add uppercase alphabet to array
        int upperChar = 65;
        int arrayIndex = 0;
        for (int i = 0; i < 26; i++)
        {
            c = upperChar;
            alpha[i] = c;
            upperChar++;
            arrayIndex++;
        }
        // add lowercase alphabet to array
        int lowerChar = 97;
        for (int j = 0; j < 26; j++)
        {
            c = lowerChar;
            alpha[arrayIndex + j] = c;
            lowerChar++;
        }
        // assign hash variable from hash received from user at command line
        string hash = argv[1];
        char a = hash[0];
        char b = hash[1];
        // assign salt variable to pass to crypt() function
        char salt[3];
        salt[0] = a;
        salt[1] = b;
        // assign variable to hold hash from generated passwords
        string cryptHash;
        // assign password variables
        char password[6] = {0};
        char d;
        char e;
        char f;
        char g;
        // assign varialbe to hold return value of compared strings
        int ret;
        // generate all one letter passwords
        for (int n = 0; n < strlen(alpha); n++)
        {
            g = alpha[n];
            password[0] = g;
            //validate
            //if validates, print password and return 0
            cryptHash = crypt(password, salt);
            ret = strncmp(cryptHash, hash, 13);
            if (ret == 0)
            {
                printf("%s\n", password);
                return 0;
            }
        }
        // if hash didn't validate yet, try two letter combinations
        for (int m = 0; m < strlen(alpha); m++)
        {
            f = alpha[m];
            password[0] = f;
            for (int n = 0; n < strlen(alpha); n++)
            {
                g = alpha[n];
                password[1] = g;
                //validate
                // if validates, print password and return 0
                cryptHash = crypt(password, salt);
                ret = strncmp(cryptHash, hash, 13);
                if (ret == 0)
                {
                    printf("%s\n", password);
                    return 0;
                }
            }
        }
        // if hash didn't validate yet, try three letter combinations
        for (int l = 0; l < strlen(alpha); l++)
        {
            e = alpha[l];
            password[0] = e;
            for (int m = 0; m < strlen(alpha); m++)
            {
                f = alpha[m];
                password[1] = f;
                for (int n = 0; n < strlen(alpha); n++)
                {
                    g = alpha[n];
                    password[2] = g;
                    //validate
                    //if validates, print password and return 0
                    cryptHash = crypt(password, salt);
                    ret = strncmp(cryptHash, hash, 13);
                    if (ret == 0)
                    {
                        printf("%s\n", password);
                        return 0;
                    }
                }
            }
        }
        // if hash didn't validate yet, try 4 letter combinations
        for (int k = 0; k < strlen(alpha); k++)
        {
            d = alpha[k];
            password[0] = d;
            for (int l = 0; l < strlen(alpha); l++)
            {
                e = alpha[l];
                password[1] = e;
                for (int m = 0; m < strlen(alpha); m++)
                {
                    f = alpha[m];
                    password[2] = f;
                    for (int n = 0; n < strlen(alpha); n++)
                    {
                        g = alpha[n];
                        password[3] = g;
                        //validate
                        //if validates, print password and return 0
                        cryptHash = crypt(password, salt);
                        ret = strncmp(cryptHash, hash, 13);
                        if (ret == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                }
            }
        }
        // if hash didn't validate yet, try 5 letter combinations
        for (int j = 0; j < strlen(alpha); j++)
        {
            c = alpha[j];
            password[0] = c;
            for (int k = 0; k < strlen(alpha); k++)
            {
                d = alpha[k];
                password[1] = d;
                for (int l = 0; l < strlen(alpha); l++)
                {
                    e = alpha[l];
                    password[2] = e;
                    for (int m = 0; m < strlen(alpha); m++)
                    {
                        f = alpha[m];
                        password[3] = f;
                        for (int n = 0; n < strlen(alpha); n++)
                        {
                            g = alpha[n];
                            password[4] = g;
                            //validate
                            //if validates, print password and return 0
                            cryptHash = crypt(password, salt);
                            ret = strncmp(cryptHash, hash, 13);
                            if (ret == 0)
                            {
                                printf("%s\n", password);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        // if none of the password hashes validaded, we did not generate the right password
        printf("All passwords were tried and hashed. No hashes matched hash input by user. Sorry!");
        return 0;

    }
    /*--- if program is executed without any comand-line argument or more than one argument
    is entered, print error message and return from main value of 1 ---*/
    else
    {
        printf("ERROR!! You must enter a hashed password. Only one argument is accepted.\n");
        return 1;
    }
}