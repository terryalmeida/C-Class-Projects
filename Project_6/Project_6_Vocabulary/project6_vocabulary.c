#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


//Terry Almeida Astacio
//3/27/2023
//Program 6: Vocabulary
//This program uses the command line to gather an input file with unsorted and some duplicated words
//and sorts it and stores unique words in uppercase in an output text file given by the second command line argument

//main function
int main(int argc, char *argv[])
{
    //error handling for more than 3 arguments
    if (argc != 3)
    {
        printf("Only 3 command arguments can be used");
        return 1;
    }

    //declaring file pointers for input and output files and assigning pIf pointer to first command argument (input file) as read-only

    FILE *pIf = fopen(argv[1], "r");

    FILE *pOf = fopen(argv[2], "w");

    //declaring integer counters i and j, max number of words variable, max_char variable, and N (total number of unique words) in words array
    int i = 0, j = 0, k = 0, max_words = 1000, max_char = 101, N1 = 0;

    //declaring words array to be stored
    char words[max_words][max_char];

    //stores words from input file into words array

    while ((fscanf(pIf, "%100s", words[N1]) == 1) && (N1 < max_words))
    {
            N1++;
    }

    //N1 is now the actual number of words in the input file

    //converts all letters to uppercase
    for (i = 0; i < N1; i++)
    {
        for(j = 0; words[i][j] != '\0'; j++)
        {
            words[i][j] = toupper(words[i][j]);
        }
    }

    //sorts words in words array using string compare and copy, along with a temporary array
    for (i = 0; i < N1; i++)
    {
        for (j = i+1; j < N1 ; j++)
        {
            if (strcmp(words[i], words[j]) > 0)
            {
                char tmp[max_char];
                strcpy(tmp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], tmp);
            }
        }
    }

    //replaces duplicates in words array and shifts the word positions

     for(i = 0; i < N1; i++)
    {
        for (j = i + 1; j < N1; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                for (k = j; k < N1 - 1; k++)
                {
                    strcpy(words[k], words[k+1]);
                }
                N1--;
                j--;
            }
        }
    }

    //store sorted uppercase words without duplicates in output file, along with a number and space before the word

    for(i = 0; i < N1; i++)
    {
        fprintf(pOf, "%d %s\n", i + 1, words[i]);
    }

    //closes input and output file
    fclose(pIf);
    fclose(pOf);

    return 0;
}
