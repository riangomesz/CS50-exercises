/* Readability exercise whose objective is to categorize the level necessary to understand the text typed by the user */

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main (void)
{
    string text = get_string("Text: ");

    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        else if (text[i] == ' ')
        {
            words++;
        }

        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    int index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",index);
    }
}
