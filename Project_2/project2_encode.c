#include <stdio.h>
#include <ctype.h>
//Terry Almeida, Program 2, Encoder: This program encodes the input characters with the pre-set algorithm.
//Built on 1/25/2023

int main()
{
    //Assign char type to ch variable
    char ch;
    //Prompt user to enter input
    printf("Enter input: ");
    //Loop to read characters inputted by user while skipping the rest of an input line.
    while (((ch = getchar()) != '\n'))  {
        //if input variable ch entered is a number, substract with character '0', add integer 6, and calculate remainder by 10, then add integer value of character '0' again, then print new ch value
        if ((ch >= '0') && (ch <= '9')){
            ch -= '0';
            ch += 6;
            ch = (ch % 10);
            ch += '0';
            printf("%c", ch);
        }
        //if character is a lowercase letter, substract with 'a' character, add 6, and calculate remainder by 26, then add 'a' again, then print new ch value
        if ((ch >= 'a') && (ch <= 'z')){
            ch = (ch - 'a');
            ch += 6;
            ch = (ch % 26);
            ch += 'a';
            printf("%c", ch);
        }
        //if character is uppercase letter, substract ch with 'A', add 6, calculate remainder by 26 and add 'A' again, then print new ch value
        if ((ch >= 'A') && (ch <= 'Z')){
            ch = (ch - 'A');
            ch += 6;
            ch = (ch % 26);
            ch += 'A';
            printf("%c", ch);
        }
        //if ch inputted is not a number, lowercase letter, uppercase letter, or a white space, then print the underscore '_' character
        if (((ch < '0') || (ch > '9')) && ((ch < 'a') || (ch > 'z')) && ((ch < 'A') || (ch > 'Z')) && (ch != ' ')){
            ch = '_';
            printf("%c", ch);
        }

    }
    //end while loop with semicolon below
    ;
    //end of program
}
