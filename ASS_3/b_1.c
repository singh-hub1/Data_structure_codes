/* Write a C program to create an array of integers.Accept a value from user and use linear search method to check
whether the given number is present in array or not. Display proper message in output */

#include<stdio.h>
 
int main()
{
   int arr[100];
   int n,i,x,f=0;
   printf("enter how many elements\n");
   scanf("%d",&n);
   
       
        printf("enter array content one by one\n");
        for(i=0;i<n;i++)
        {
            printf("arr[%d]=",i);
            scanf("%d",&arr[i]);
        }
    
        printf("enter a number to be search\n");
        scanf("%d",&x);

    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
         {
             printf("%d is found at %d location in the array\n",x,i+1);
             f=1;
             break;
         }
    }
    if(f==0)
     printf("sorry given %d is not found at any location in the array\n",x);
   return 1;
}