
#include<stdio.h>
#include<stdlib.h>
void main() {
    int num[50],target,n;
    printf("Enter the number of elements");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (int i=0;i<n;i++) {
        printf("Element %d : ",i+1);
        scanf("%d",&num[i]);
    }
    printf("Enter element to search: ");
    scanf("%d",&target);
    for (int i=0;i<n;i++) {
        if (num[i]==target) {
            printf("Element found at position %d\n",i);
            exit(0);
        }
    }
    printf("Element not found in the array");

}