#include <stdio.h>
//Terry Almeida
//Project 4: Median
//This program computes the number of median numbers in an array of an odd number of elements.
//declare prototype functions to compute median and quicksort
int compute_median(int *a, int n);

//quicksort function prototype from textbook
void quicksort(int a[], int low, int high);
//split function prototype from textbook

int split (int a[], int low, int high);

//main function
int main()
{
    //declaring array size as int N
    int i, N;

    //Prompt user for array size and save input into size variable
    printf("Enter array size: ");
    scanf("%d", &N);

    //declare array a as int array with size of size variable
    int arr[N];

    //loop to prompt user to enter array elements
    printf("Enter array elements: ");
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    //quicksort function used to sort arr array
    quicksort(arr, 0, N - 1);

    //print output of number of median numbers in array
    printf("Output: %d\n", compute_median(arr, N));

}
//quicksort function
void quicksort(int a[], int low, int high)
{
    int middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}
//split function
int split (int a[], int low, int high)
{
    int part_element = a[low];

    for(;;)
    {
        while (low < high && part_element <= a[high])
            high--;
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= part_element)
            low++;
        if (low >= high) break;
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}

//compute amount of median numbers in array
int compute_median(int *a, int n)
{
    //declaring variables i, med1, med2, and med3 and number of medians as int
    int i, med1, med2, med3, num_of_medians = 0;

    //median one is number of array elements n divided by 2
    med1 = (n / 2);
    //second median is med1 +1
    med2 = (med1 + 1);
    med3 = (med1 - 1);
    if ((*(a + med1 - 1)) != (*(a + med2 - 1)) && (*(a + med1 - 1)) != (*(a + med3 - 1)) )
        return 3;
    //for loop to run through the array and return 1 if values of array med1 and med2 are not the same
    if ((*(a + med1 - 1)) != (*(a + med2 - 1)))
        return 1;
    //for loop to add number of medians if medians are equal to the array value
    for(i = 0; i < n; i++)
    {
        if (((*(a + i)) == (*(a + med1 - 1))) || (*(a + i) == (*(a + med2 - 1))) || (*(a + i) == (*(a + med1))))
            num_of_medians++;
    }

    //return number of medians
    return num_of_medians;
}


