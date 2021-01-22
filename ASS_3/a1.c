/*Write a C program to accept n elements from user store it in an array. Accept a value from the
user and use linear/Sequential search method to check whether the value is present in array or
not. Display proper message*/
#include<stdio.h>
#include<stdlib.h>
 int linear_search();
int main()
{
   int *ptr;
   int n,i;
   printf("enter how many elements\n");
   scanf("%d",&n);
   ptr=(int*)malloc(n*sizeof(int));
   if(ptr==NULL)
      printf("allocation failed\n");
       
        printf("enter array content one by one\n");
        for(i=0;i<n;i++)
        {
            printf("ptr[%d]=",i);
            scanf("%d",&ptr[i]);
        }
        int x;
        printf("enter a number to be search\n");
        scanf("%d",&x);
        int k=linear_search(ptr,n,x);
        if(k==-1)
        {
            printf(" sorry given number is not found at any location in the array\n");
        }
        else
        {
            printf("%d is found at %d location in the array\n",x,k+1);
        }
        return 0;
}
int linear_search(int *arr,int n,int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        return i;
    }
    return -1;
}