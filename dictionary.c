// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// counter for number of words
int count = 1;

// Number of buckets in hash table
const unsigned int N = 3109;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int compare = 0 ;
    char input [LENGTH + 1] ;
    strcpy ( input, word ) ;
    int hashcode = hash (input) ;
    node (*traverser) = calloc ( 1, sizeof (node) ) ;
    strcpy ( table[hashcode] -> word, traverser -> word ) ;
    table[hashcode] -> next = traverser -> next;
    while (traverser -> next != NULL )
    {   compare = strcasecmp (input, traverser -> word) ;
        if ( compare == 0 )
        {  return true;
        }
        traverser = traverser -> next ;
    }

    free (traverser) ;
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    char input [LENGTH + 1] ;
    strcpy ( input, word ) ;
    int current = 0 ;
    int total = 0 ;
    unsigned int hash = 0 ;
    for ( int x = 0; x < strlen (input) ; x++ )
    {
        current = input [x] % 97 ;
        total = total + current ;
    }
    hash = total % N ;
    return hash ;

}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{   int hashcode = 0 ;
    FILE *raw = fopen (dictionary, "r") ;
    if (raw == NULL)
    {
        printf("Could not open file \n");
        return false;
    }

    char entry[LENGTH];
    node (*current_node) = calloc ( 1, sizeof (node)) ;
    if (current_node == NULL)
    {
        printf ("Not enough memory") ;
        return false ;

    }
    while ( fscanf ( raw, "%s", entry ) != EOF)
    {
           hashcode = hash (entry) ;
           strcpy (current_node -> word, entry)  ;
           current_node -> next = NULL ;
           if ( table[hashcode] == '\0')                      // If it is the first node of linked list
           {
               strcpy ( table[hashcode] -> word, current_node -> word ) ;
               table[hashcode] -> next = current_node -> next;
           }
           if (table[hashcode] != '\0' && table[hashcode] -> next == NULL )     // If it is the second node of the linked list
           {
               node (*new) = calloc ( 1, sizeof(node)) ;
               if (new == NULL)
               {
                   printf ("Not enough memory") ;
                   return false;
               }
               strcpy ( new -> word, current_node -> word ) ;
               new -> next = current_node -> next ;
               table[hashcode] -> next = new ;
           }

           if (table[hashcode] != '\0' && table[hashcode] -> next != NULL )   // If it is the >2nd node of the linked list
           {
               node (*new) = calloc ( 1, sizeof(node)) ;
               if (new == NULL)
               {
                   printf ("Not enough memory") ;
                   return false;
               }
               strcpy ( new -> word, current_node -> word ) ;
               new -> next = table[hashcode] -> next ;
               table[hashcode] -> next = new ;
           }
           count++ ;

           }

    free (current_node) ;
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (count >1)
    {return count ; }
    else if (count == 1)
    { return 0 ;    }

    return 0 ;

}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
