#include <stdio.h>
//Terry Almeida Astacio
//Project 4: Minutes
/*This program uses the find_minute function to find the number of minutes
when  a user will stop watching a show afer inputting the number of interesting
minutes and where in the 45-minute show they are located*/

/*First we are declaring the prototype function that we will use to find
the show minute.*/
int find_minute(int *minutes, int n);

//main function
int main(void)
{
    //Declaring total interesting minutes as variable int, along with i to be counter
    int tot_int_min, i;

    //Prompt the user to enter interesting minutes and save into tot_int_min variable
    printf("Enter the number of interesting minutes: ");
    scanf("%d", &tot_int_min);

    //declaring array as m with number of elements ad tot_int_min
    int m[tot_int_min];

    //prompt the user for the location in the 45-minute slot of the interesting minutes
    printf("Enter the interesting minutes: ");
    for (i = 0; i < tot_int_min; i++)
        scanf("%d", &m[i]);

    /*output the function find_minute as integer with variable m as the array for pointer minutes
    and tot_int_min as n*/
    printf("Output: %d\n", find_minute(m, tot_int_min));

    //exit program
    return 0;
}
//find minute function with int pointer *minutes and int n
int find_minute(int *minutes, int n)
{
    //declare variable i as counter for for loop
    int i;

    //for loop to run through the array
    for(i = 0; i < (n - 1); i++)
    {
        //if the first minute (m[0])is greater than 7, then return 7 as output
        if (*minutes > 7)
            return 7;

        /*if there is a difference greater than seven between two minutes
        return the value of the smaller minute plus 7 boring minutes*/
        if (((*(minutes + i + 1)) - (*(minutes + i))) > 7)
        {
            //if the smaller value plus 7 is greater than 45, return 45
            if (((*(minutes + i)) + 7) > 45)
                return 45;

            //otherwise return the smaller value plus 7
            else if (((*(minutes + i)) + 7) < 45)
                return (((*(minutes + i)) + 7));
        }

    }
    // if the for loop runs and no minutes difference is greater than 7, and the last value + 7 is greater than 45
    if (((*(minutes + n - 1) + 7)) > 45)
        return 45;
    //otherwise return the last value + 7
    else
        return ((*(minutes + n - 1)) + 7);

}
