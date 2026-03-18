#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int size){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
        
    }
}
void selectionSort(int arr[], int size){
    int min;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i], &arr[min]);        
    }
    
}
void insertionSort(int arr[], int size){
    int i, key, j;
    for (i = 1; i < size; i++){
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int partition(int arr[], int low, int high){
    int pivot = arr[high], i = low-1;
        for(int j = low; j < high; j++){
            if (arr[j] <= pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}
void quickSort(int arr[], int low, int high){
    if (low >= high)
        return;
    int pivotIndex = partition(arr, low, high);
    quickSort(arr, low, pivotIndex-1);
    quickSort(arr, pivotIndex+1, high);
}
void merge(int arr[], int low, int mid, int high){
    int n1 = mid-low+1;
    int n2 = high-mid;
    int left[n1], right[n2];
    int i, j, k;
    for (i = 0; i < n1; i++)
        left[i] = arr[low+i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid+1+j];
    i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];
}
void mergeSort(int arr[], int low, int high){
    if(low >= high)
        return;
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
int bSearch(int arr[], int size, int target){
    int low = 0, high = size-1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (target == arr[mid])
            return mid;
        else if (target < arr[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}
int main(){
    int n = 5, arr[5] = {1,2,3,4,5}, arr2[5] = {40,50,1,23,4}, target = 4, found = 0;
    //linear search
    for (int i = 0; i < n; i++)
    {
        if (target == arr[i])
        {
            printf("target found at index %d\n",i);
            found++;
        }
    }
    if(found == 0)
        printf("target not found");
    //binary search
    printf("target found at %d\n", bSearch(arr,n,4));
    //bubbleSort(arr2, 5);
    //selectionSort(arr2, 5);
    //insertionSort(arr2, 5);
    //quickSort(arr2, 0, n-1);
    mergeSort(arr2, 0, n-1);
    for (int i = 0; i < 5; i++)
        printf("%d\n",arr2[i]);
    
    return 0;
}