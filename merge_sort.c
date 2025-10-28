#include<stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftarray[n1], rightarray[n2];
    for (i = 0; i < n1; i++)
    {
        leftarray[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        rightarray[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (leftarray[i] <= rightarray[j])
        {
            arr[k] = leftarray[i];
            i++;
        }
        else
        {
            arr[k] = rightarray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k++] = leftarray[i++];
    }
    while (j < n2)
    {
        arr[k++] = rightarray[j++];
    }
}

void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void main()
{
    int arr[] = {20, 50, 10, 30, 5, 70, 50};
    int left = 0, right = sizeof(arr) / sizeof(arr[0]) - 1;
    mergesort(arr, left, right);
    for (int i = 0; i < right + 1; i++)
    {
        printf("%d ", arr[i]);
    }
}
