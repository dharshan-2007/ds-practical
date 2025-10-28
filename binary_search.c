
#include<stdio.h>
#include<stdlib.h>
void main() {
    int num[50],target,n,start,end,mid,i;
    printf("Enter total number of elements : ");
    scanf("%d",&n);
    printf("Enter elements in sorted order\n");
    for (i=0;i<n;i++) {
        printf("Enter %d element : ",i+1 );
        scanf("%d",&num[i]);
    }
    printf("Enter element to be found");
    scanf("%d",&target);
    start=0;
    end=n;
    while (start<=end) {
        mid=(start+end)/2;
        if (num[mid]==target) {
            printf("Element found at index %d",mid);
            return;
        }
        else if (num[mid]<target) {
            start=mid+1;
        }
        else {
            end=mid-1;
        }

    }
    if (start>end) {
        printf("Element not found in array");
    }
}