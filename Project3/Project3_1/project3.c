#include <stdio.h>

int main(void)
{
    int i, n;

    printf("Enter the length of the input array:");
    scanf("%d", &n);
    int a[n];

    printf("Enter the array elements:");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = (n - 1); i > 0; i--){
        if ( (a[i] < (a[i-1])) || ((((a[i]) % a[i-1]) == 0))){
            printf("Output: no");
            return 0;
        }
    }
    printf("Output: yes");

}

