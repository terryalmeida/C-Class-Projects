#include <stdio.h>

//Terry Almeida, Project #1: Event Package Calculator, Written on 01/20/2023
/*This program allows user to enter a package selection,
number of hours and people and the program will calculate and print the charge*/

int main()
{
    int package;
    int hours;
    int people;
    double cost;


    printf("Please select from three packages: 1, 2 and 3\n");

    printf("Enter package selection:");
    scanf("%d", &package);

    if (package < 1 || package > 3)
        printf("Invalid selection. Select from 1 to 3.");
        return 0;

    printf("Enter hours:");
    scanf("%d", hours);
    if (hours < 1 || hours > 4)
        printf("Invalid input. Enter a positive number less than or equal to 4 for number of hours.");
        return 0;

    scanf("%d", people);
        if ((package == 1 && people < 50) || (package == 2 && people < 80) || (package == 3 && people < 30))
            printf("Not meeting minimum requirement for number of guests.");
            return 0;
        if ((package == 1 && people > 200) || (package == 2 && people > 300) || (package == 3 && people < 150))
            printf ("Exceeded maximum number of guests.");
            return 0;


    if (package == 1 && hours == 1)
        cost = 50 + (people * 25);



    printf("Charge($):",cost);


    return 0;
}
