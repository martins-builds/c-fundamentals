#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sumArray(int *arr, int size){
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += *arr++;
    return sum;
}

int findSmallest(int *arr, int size){
    int smallest = *arr;
    for (int i = 1; i < size; i++)
    {
        if (smallest > *arr)
            smallest = *arr;
        arr++;
    }
    return smallest;
}

float findAverage(int *arr, int size){
    int sum = 0;
    float average = 0.0;
    for (int i = 0; i < size; i++)
        sum += *arr++;
    average = (float)sum/size;
    return average;
}

void countEvenOdd(int *arr, int size){
    int countEven = 0, countOdd = 0;
    for (int i = 0; i < size; i++)
    {
        if (*arr % 2 == 0)
            countEven++;  
        else
            countOdd++;
        arr++;
    }
    printf("\nThere are %d number of evens", countEven);
    printf("\nThere are %d number of odds", countOdd);
}

void reverseArray(int *arr, int size){
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end)
    {
        swap(start, end);
        start++;
        end--;
    }
    
}
int main(){
    int arr[5] = {1,2,3,4,5};
    reverseArray(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }
    
    return 0;
}