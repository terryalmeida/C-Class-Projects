#include <stdio.h>
#include <ctype.h>
#include <string.h>
//Terry Almeida,
//Program 5, Encoder: This program encodes the input characters from the command line arguments
//Built on 3/3/23

//Declaring encode function prototype
void encode(char *input, char *output);

//main function with command line argument integration
int main(int argc, char *argv[])
{
    //declaring i as integer for counter
    int i;

    //declaring result[1001] as a 1001 element array that will save the output from the encode function
    char result[1001];

    //if there are more than 2 arguments, run loop to print characters in every string from the encode funtion
    if (argc >= 2)
    {
        printf("Output:");

        //loop to print all the arguments as encoded strings
        for (i = 1; i < argc; i++)
        {
            strcpy(result, argv[i]);
            encode(argv[i], result);
        }
    }

    //if 1 argument, print invalid input
    if (argc == 1)
        printf("Invalid input!");
}

//encode function with input and output pointers
void encode(char *input, char *output)
{
    //declaring variable i as integer for counting
    int i;
    //declaring variable ch as character
    char ch;

    //for loop that encodes the character elements of the input array
    for (i = 0; i < strlen(input); i++)
    {
        ch = input[i];

        if ((ch >= '0') && (ch <= '9'))
        {
            ch -= '0';
            ch += 6;
            ch = (ch % 10);
            ch += '0';
            printf("%c", ch);;
        }
        //if character is a lowercase letter, substract with 'a' character, add 6, and calculate remainder by 26, then add 'a' again, then print new ch value
        if ((ch >= 'a') && (ch <= 'z'))
        {
            ch = (ch - 'a');
            ch += 6;
            ch = (ch % 26);
            ch += 'a';
            printf("%c", ch);;
        }
        //if character is uppercase letter, substract ch with 'A', add 6, calculate remainder by 26 and add 'A' again, then print new ch value
        if ((ch >= 'A') && (ch <= 'Z'))
        {
            ch = (ch - 'A');
            ch += 6;
            ch = (ch % 26);
            ch += 'A';
            printf("%c", ch);;
        }
        //if ch entered is not a number, lowercase letter, uppercase letter, or a white space, then print the underscore '_' character
        if (((ch < '0') || (ch > '9')) && ((ch < 'a') || (ch > 'z')) && ((ch < 'A') || (ch > 'Z')) && (ch != ' '))
        {
            ch = '_';
            printf("%c", ch);
        }

    }
}
