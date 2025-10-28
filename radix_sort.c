#include<stdio.h>

int getmax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countsort(int arr[], int n, int exp)
{
    int res[n], count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        res[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = res[i];
    }
}

void radixsort(int arr[], int n)
{
    int max = getmax(arr, n);
    for (int i = 1; max / i > 0; i *= 10)
    {
        countsort(arr, n, i);
    }
}

void main()
{
    int arr[] = {70, 20, 10, 40, 50, 70, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
