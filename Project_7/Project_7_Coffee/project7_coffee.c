#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Terry Almeida Astacio
//Created on 4/3/23
//Project 7: Coffee
//This program sorts a coffee by total score list in descending order


//here we are declaring the coffee structure outside of the main function so that the main and void function have access to it
 struct coffee {
        char country[151];
        char region[151];
        char owner[151];
        char variety[151];
        double score;
};

//declaring selection sort function
void selection_sort_coffee(struct coffee list[], int n);

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

    //call selection sort coffee function to sort the coffee list with N1 amount of coffees
    selection_sort_coffee(list, N1);

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

//selection sort function with input coffee list structure and n number of coffees after counting
void selection_sort_coffee(struct coffee list[], int n)
{
    //declaring counter i and largest
    int i, largest = 0;

    //declaring temporary coffee structure to hold variables when moving them in descending order
    struct coffee temp;

    //if there is only one coffee in the list, return
    if (n == 1)
        return;

    //for loop to determine if a coffee score is smaller than the current largest one
    for (i = 1; i < n; i++)
    {
        if (list[i].score < list[largest].score)
            largest = i;
    }

    //if largest coffee score is smaller than the second to last
    //this will copy the second to last to the temporary structured array
    //copy the largest one to the second to last
    //and copy the temp one to the largest one
    if (largest < n - 1)
    {
        temp = list[n-1];
        list[n-1] = list[largest];
        list[largest] = temp;
    }

    //recursive function to continue sorting
    selection_sort_coffee(list, n - 1);
}

