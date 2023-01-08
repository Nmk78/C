#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int i, b, key;
// int num = 0;
string plaintext, ciphertext;
bool Digits;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage './caesar key': \n");
        return 0;
    };

    for (b = 0; b < strlen(argv[1]); b++)
    {
        if (!isdigit(argv[1][b]))
        {
            printf("Usage './caesar key': \n");
            Digits = false;
        }

        Digits = true;
        // this is just for Checking Purpose
        //  printf("%s\n", argv[1]);
        //  printf(Digits? "true" : "false");
        //  printf("\n");

        // return 0;
    }

    if (Digits == true)
    {
        key = atoi(argv[1]);
        // key =(argv[1]);

        // printf("%d",key);
        // int keylength = strlen(argv[1]);
        plaintext = get_string("Enter Your Plain Text : ");
    };

    // for (int a = 0, a < strlen(plaintext); a++)
    // {
    //     if ((plaintext[i] >= 'a' || plaintext[i] >= 'A') && (plaintext[i] <= 'z' || plaintext[i] <= 'Z'))
    //     {
    //         printf(("%c", plaintext[a] - 65 + key) % 26 + 65);

    //     }
    // }

for (i = 0; i < strlen(plaintext); i++)
        {
            // checking if it is lowercase 97 = a to 112 = z and if it + 13 characters along.
            if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                printf("%c", (((plaintext[i] - 'a') + key) % 26) + 'a'); // print out lowercase with key
            } // if it it between uppercase A and C
            else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                printf("%c", (((plaintext[i] - 'A') + key) % 26) + 'A'); // print out uppercase with key
            }
            // non-alphabetic characters
            else
            {
                ciphertext[i] = plaintext[i];
            }

    }
    printf("\n");
}