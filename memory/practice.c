#include<stdio.h>
#include<stdlib.h>

int main(){

    int *a = (int*) malloc(sizeof(int));
    int *arr = (int*) calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    if (a == NULL)
    {
        printf("Couldn\'t allocate memory");
        return 0;
    }
    *a = 2;
    printf("\n%d\n", *a);
    free(a);

    if (arr == NULL)
    {
        printf("Couldn\'t allocate memory to array");
        return 0;
    }
    printf("\nEnter values");
    for (int i = 0; i < 5; i++)
        scanf("%d", &arr[i]);
    printf("\nValues are: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    arr = (int*) realloc(arr, sizeof(int) * 10);
    if (arr == NULL)
    {
        printf("Couldn\'t allocate memory to array");
        return 0;
    }
    printf("\nEnter values");
    for (int i = 5; i < 10; i++)
        scanf("%d", &arr[i]);
    printf("\nValues are: ");
    for (int i = 5; i < 10; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}