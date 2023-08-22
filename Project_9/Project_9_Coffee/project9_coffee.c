#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Terry Almeida Astacio
//Created on 4/3/23
//Project 9: Coffee with Qsort
//This program sorts a coffee by total score list in descending order using qsort


//here we are declaring the coffee structure outside of the main function so that the main and void function have access to it
 struct coffee {
        char country[151];
        char region[151];
        char owner[151];
        char variety[151];
        double score;
};

//declaring selection sort function
//void selection_sort_coffee(struct coffee list[], int n);
int compare_coffee(const void *p, const void *q);

//main function
int main()
{
    //declaring counter integers
    int i = 0, N1 = 0;

    //declaring file name arrays
    char input_file[50];
    char output_file[50];

    //Prompts the user to enter a file name and stores the string input in the input file array
    printf("Enter the file name:");
    scanf("%s", input_file);

    //copies the string part of sorted_ to the output file
    strcpy(output_file, "sorted_");

    //appends the input file string to the output file
    strcat(output_file, input_file);

    //prints the output file name
    printf("Output file name:\n%s\n", output_file);

    //creates a file pointer and opens the input file as read only
    FILE *pIf = fopen(input_file, "r");

    //error handling if input file cannot be opened
    if (pIf == NULL)
    {
        printf("Error: Input File cannot be opened.\n");
        return 1;
    }

    //creates and assigns file pointer to newly created output file that is write only
    FILE *pOf = fopen(output_file, "w");

    //error handling if output file is null
    if (pOf == NULL)
    {
        printf("Error: Output file cannot be opened.\n");
        return 1;
    }

    //creates structure for coffee list array to store each coffee structure
    struct coffee list[100];

    //reads input file line by line, while incrementing each amount of coffee in the list
    //and adding each element of each coffee to the coffee list elements
    while ((fscanf(pIf, "%[^,],%[^,],%[^,],%[^,],%lf\n", list[N1].country, list[N1].region, list[N1].owner, list[N1].variety, &list[N1].score) == 5) && (N1 < 100))
    {
            N1++;
    }


    //call qsort to sort the coffee list
    qsort(list, list->score, sizeof(struct coffee), compare_coffee);

    //print loop to print each line of coffee onto output file
    for(i = 0; i < N1; i++)
    {
        fprintf(pOf, "%s, %s, %s, %s, %.02f\n", list[i].country, list[i].region, list[i].owner, list[i].variety, list[i].score);
    }

    //closes input and output file
    fclose(pIf);
    fclose(pOf);

    return 0;
}

//compare coffee function to be used in qsort in main
//adapted from compare parts function and sorting integers exercise
int compare_coffee(const void *p, const void *q)
{
    //assign p and q to variables of type struct part
    const struct coffee *p1 = p;
    const struct coffee *q1 = q;

    //if coffee score pointed by p1 is greater than q1 score, return -1
    if (p1->score > q1->score)
        return -1;
    //if the scores are equal, return 0
    else if (p1->score == q1->score)
        return 0;
    //otherwise return 1 if q1 is larger than p1
    else
        return 1;
}

