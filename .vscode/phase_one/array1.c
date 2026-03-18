#include<stdio.h>
#include<limits.h>
int main(){
    int arr[10], big, sma, secBig, secSma, num, sum = 0, count = 0, even_count = 0, odd_count = 0;
    float avg; 

    printf("Enter 10 numbers: ");
    for (int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    big = arr[0];
    sma = arr[0];
    secBig = INT_MIN;
    secSma = INT_MAX;
    for (int i = 1; i < 10; i++)
    {
        if (big < arr[i])
        {
            secBig = big;
            big = arr[i];
        }
        else if (arr[i] > secBig)
        {
            secBig = arr[i];
        }

        if (sma > arr[i])
        {
            secSma = sma;
            sma = arr[i];
        }
        else if (secSma > arr[i])
        {
            secSma = arr[i];
        }              
    }

    printf("\nBiggest element is %d\n", big);
    printf("\nSecond biggest element is %d\n", secBig);

    printf("\nSmallest element is %d\n", sma);
    printf("\nSecond smallest element is %d\n", secSma);

    for (int i = 0; i < 10; i++)
        sum = sum + arr[i];
    avg = sum / 10.0;

    printf("\nTotal sum is %d\n", sum);
    printf("\nAverage is %.2f\n", avg);

    printf("\nReversal of your array is: ");
    for (int i = 9; i >= 0; i--)
        printf("%d ", arr[i]);

    printf("\nEnter a number to search: ");
    scanf("%d", &num);
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == num)
            count++;
    }
    printf("\n%d appears %d times\n", num, count);

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2 == 0)
            even_count++;
        else
            odd_count++;
        
    }
    printf("\nTotal even numbers are: %d", even_count);
    printf("\nTotal odd numbers are: %d", odd_count);

    for (int i = 0; i < 10; i++)
    {
        if (big < arr[i])
            big = arr[i];
        
    }

    return 0;
}