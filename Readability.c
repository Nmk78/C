#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text : ");

    int everyLetterIncludingSpaces = strlen(text);
    int letter = 0;
    int word = 1; //cuz it will skip the first phase cuz he see the first space after first phrase
    int sentence = 0;



    for(int i = 0; i < everyLetterIncludingSpaces; i++ )
    {
        // printf("%c \n", text[i]);
        if(isalpha(text[i]) )
        {
            letter++;
        }
        if(text[i] == ' ')
        {
            word++;
        }
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence ++;
        }
    }
    // printf("%d\n letter ",letter);
    // printf("%d\n word ",word);
    // printf("%d\n sentence ",sentence);
    // printf("%d\n everyCount ",everyLetterIncludingSpaces);

    float L = ((float)letter / (float)word) * 100;
    float s = ((float)sentence / (float)word) * 100;
    float subindex = 0.0588 * L - 0.296 * s - 15.8;
    int index = round(subindex);

        if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}