//Write a C program to accept and sort n elements in ascending order by using bubble sort using header file.//
#include<stdio.h>
#include "bubble1.h"
void read_array(int[],int);
void display_array(int[],int n);
void bubble_sort(int[],int n);
int main()
{
    int arr[10];
    int n;

    printf("enter how many numbers u want\n");
    scanf("%d",&n);

     read_array(arr,n);

     printf("before sorting array elements\n");
     printf("number are as follows\n");

     display_array(arr,n);
   

     bubble_sort(arr,n);

     printf("\nafter sorting the array element\n");
     printf("number are as follows\n");

     display_array(arr,n);

    return 1;
}



