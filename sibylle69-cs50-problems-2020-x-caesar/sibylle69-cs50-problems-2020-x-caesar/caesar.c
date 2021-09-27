#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;

    //if not only one argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (i = 0; i < strlen(argv[1]) ; i++)
    {
        if (! isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //ask for the text
    string string = get_string("plaintext:");
    printf("ciphertext: ");

    int k = atoi(argv[1]);
    for (j = 0; j < strlen(string); j++)
    {
        //if character is lowercase
        if (string[j] >= 'a' && string[j] <= 'z')
        {

            printf("%c", (string[j] - 'a' + k) % 26 + 'a');
        }

        //is character is uppercase
        else if (string[j] >= 'A' && string[j] <= 'Z')
        {
            printf("%c", (string[j] - 'A' + k) % 26 + 'A');
        }

        //if character is punctuation or a whitespace
        else if (ispunct(string[j]) || string[j] == ' ')
        {
            printf("%c", string[j]);
        }
    }

    printf("\n");
    return 0;

}


