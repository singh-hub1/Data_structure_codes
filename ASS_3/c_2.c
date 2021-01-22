/*Write a C program to accept n elements from user store it in an array. Accept a value from the user
and use recursive binary search method to check whether the value is present in array or not.*/

#include<stdio.h>

int binary_search();
int main()
{
    int arr[100],n;
    int i;
    
    printf("enter how many number u want\n");
    scanf("%d",&n);
    
    printf("array content\n");
    for(i=0;i<n;i++)
    {
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    } 
    int x;
    printf("enter a number to be search\n");
    scanf("%d",&x);
    int k=binary_search(arr,0,n-1,x);
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

int binary_search(int arr[100],int lower,int higher,int x)
{
    int middle;
    if(lower>higher)
       return -1;

     middle=(lower+higher)/2;
    if(arr[middle]==x)
      return middle;
      else if( x < arr[middle] )
         binary_search(arr,lower,middle-1,x);
         else
             binary_search(arr,middle+1,higher,x);
}
