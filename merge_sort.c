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
        rightarray[j] = arr[mid - 1 + i];
    }
    i = 0;
    j = 0;
    k = mid;
    while (i < n1 && j < n2)
    {
        if (leftarray[i] <= rightarray[j])
        {
            arr[k] = leftarray[i];
            i++;
        }
        else
        {
            arr[k] = rightarray[k];
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
        arr[k++]=rightarray[j++];
    }
}
