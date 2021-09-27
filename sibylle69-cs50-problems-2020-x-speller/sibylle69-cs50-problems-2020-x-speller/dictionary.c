// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;
unsigned int word_count;
char *copy;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor = NULL;
    copy = malloc(46);
    for (int i = 0, n = (strlen(word)); i < n + 1; i++)
    {
        copy[i] = tolower(word[i]);
    }

    int index = hash(copy);
    free(copy);
    return true;
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c);
    }
    return (hash % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //open dict file
    FILE *list = fopen(dictionary, "r");
    if (list != NULL)
    {
        char buffer[LENGTH + 1];

    //loop through each word and copy in new node until end of file
        while (fscanf(list, "%s", buffer) != EOF)
        {
            word_count++;

            //create new node for each word
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                unload();
                return false;
            }
            else
            {
                strcpy(n->word, buffer);
                int index = hash(n->word);
                n->next = table[index];
                table[index] = n;
            }
        }
    }
    else
    {
        return 0;
    }
    fclose(list);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        return true;
    }
    return false;
}
