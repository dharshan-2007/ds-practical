
#include<stdio.h>

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int p = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= p && i <= high - 1)
            i++;
        while (arr[j] > p && j > low + 1)
            j--;
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void main()
{
    int arr[] = {20, 50, 60, 10, 40, 30};
    int low = 0;
    int high = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, low, high);
    for (int i = 0; i < high; i++)
    {
        printf("%d ", arr[i]);
    }
}
