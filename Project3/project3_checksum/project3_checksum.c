#include <stdio.h>
//Terry Almeida
//Date Created: 2/6/2023
//Project 3, Checksum
//This program uses a recursive function to map an integer into a single digit to be used as a checksum

//declare checksum function before main
long checksum(long n);

//main function
int main()
{
    //declare number and output as long integers
    long number, output;

    //prompt user for number input
    printf("Input: ");
    scanf("%ld", &number);

    //assign variable to checksum function
    output = checksum(number);

    //print output variable with final checksum number
    printf("Checksum: %ld", output);
}

//checksum function as long integer
long checksum (long n)
{
    //if number is 1-9, return number
    if (n <= 9)
        return n;
    /*otherwise use recursive checksum function to repeatedly add digits to each other
    until input is 1-9 */
    else
        return checksum((n % 10) + checksum(n / 10));
}
