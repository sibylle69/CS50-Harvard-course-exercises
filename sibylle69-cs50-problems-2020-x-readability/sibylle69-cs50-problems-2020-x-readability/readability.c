#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    //ask to prompt the text
    string string = get_string("Text: \n");

    int word = 0;
    int ltrs = 0;
    int stce = 0;
    int i = 0;

    //read through the text
    for (i = 0; i < strlen(string); i++)
    {
        //if character
        if (isalpha(string[i]))
        {
            ltrs++;
        }
        //fir each whitespace count a word
        if (string[i] == ' ')
        {
            word++;
        }
        //count the sentences
        if (string[i] == '!' || string[i] == '.' || string[i] == '?')
        {
            stce++;
        }
    }

    //calculate the grade
    float index = 0.0588 * (float)ltrs / (word + 1) * 100 - 0.296 * (float)stce / (word + 1) * 100 - 15.8;

    //if the grade is greater than 16
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        //round up to the nearest integer
        index = round(index);
        index = (int)index;
        printf("Grade %i\n", (int)index);
    }

}
