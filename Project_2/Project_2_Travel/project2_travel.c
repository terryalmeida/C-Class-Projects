#include <stdio.h>
#include <stdlib.h>
//Terry Almeida, Project 2: Task#2 - Travel Fast
//Started on 1/30/23
//This program calculates the amount of days it would take spacecraft B to travel faster than spacecraft A
//Spacecraft A doubles its speed daily, while Spacecraft B triples its speed daily
int main()
{
    //declaring variables such as initial spacecraft speed, days, amount of cases and case counter as int
    int init_spd_a;
    int init_spd_b;
    int days;
    int case_counter = 0;
    int amount_cases;

    //Prompt user to enter number of cases to be displayed
    printf("Number of cases:");
    scanf("%d", &amount_cases);

    //Loop to display amount of cases with prompts
    while (case_counter < amount_cases){

        //Adding to case counter every time the loop runs
        case_counter++;
        //This resets day to zero every time the loop re-runs
        days = 0;

        //Prompt for Speed of A and B spacecrafts
        printf("Speed of A:");
        scanf("%d", &init_spd_a);

        printf("Speed of B:");
        scanf("%d", &init_spd_b);

        //Loop to calculate days for B to go faster than A
        while (init_spd_b <= init_spd_a){
            init_spd_a = (init_spd_a * 2);
            init_spd_b = (init_spd_b * 3);
            days++;
        }
        ;

        //display the Case number and the days it would take based on the speeds entered
        printf("Case #%d: %d day(s)\n", case_counter, days );
    }
    ;

}
