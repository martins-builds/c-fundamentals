#include<stdio.h>
int main(){

    int x = 25, arr[5] = {5,10,15,20,25}, sum = 0, largest = 0, evenCount = 0, oddCount = 0;
    int *ptr = &x, *ptrarr = arr;

    printf("\nValue of X = %d\n", x);
    printf("Address of X = %p\n", &x);
    printf("Value of X using pointer = %d\n", *ptr);
    printf("Address of X using pointer %p\n", ptr);

    for (int i = 0; i < 5; i++)
        printf("\n%d\n", arr[i]);
    for (int *ptrarr = arr; ptrarr < arr + 5; ptrarr++){
        printf("\n%d\n", *ptrarr);
        sum = sum + *ptrarr;
        if(largest < *ptrarr)
            largest = *ptrarr;
        if (*ptrarr % 2 == 0)
            evenCount++;  
        else
            oddCount++;
    }
    printf("\nSum is %d", sum);
    printf("\nLargest is %d", largest);
    printf("\nThere are %d number of evens", evenCount);
    printf("\nThere are %d number of odds", oddCount);

    return 0;
}                                 