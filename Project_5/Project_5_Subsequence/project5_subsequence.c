#include <stdio.h>
#include <ctype.h>
//Terry Almeida
//Buld on 3/2/23
//Project 5: Subsequence
//This program checks if word A is a subsequence of word B in a case-insensitive manner.

//main function
int main()
{
    //declaring variables i and j for counters, n for array length, and yes as indicator, all declared as integers
    int i, j, n = 1001;

    //declaring word 1 and 2 arrays with length n
    char word_1[n], word_2[n];

    //prompt to enter first word and save it to word_1 array as string
    printf("Enter first word: ");
    scanf("%s", word_1);

    //prompt to enter second word and save it to word_2 array as string as well
    printf("Enter second word: ");
    scanf("%s", word_2);

    //loop to make word 1 and 2 lowercase to make comparison easier.
    for (i = 0; i < (n - 1); i++)
    {
        word_1[i] = tolower(word_1[i]);
        word_2[i] = tolower(word_2[i]);
    }

    //loop to check if every letter in word_1 is also found in word_2
    for (i = 0, j = 0; word_1[i] && word_2[j]; j++)
    {
        if (word_1[i] == word_2[j])
            i++;
    }

    //when word 1 last character reaches null print yes
    if (word_1[i] == '\0')
        printf("YES");

    //otherwise print no
    else
        printf("NO");
    //end program
    return 0;

}
