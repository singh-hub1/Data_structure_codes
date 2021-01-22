/*Write a C program to accept n elements from user store it in an array. Accept a value from the user
and use Non- recursive binary search method to check whether the value is present in array or not.
Display proper message in output.
*/

#include<stdio.h>

int main()
{
    int A[100];
    int x,n,i;
    int flag=0;
    printf("enter how many number u want\n");
    scanf("%d",&n);
    printf("enter array content one by one\n");
        for(i=0;i<n;i++)
        {
            printf("A[%d]=",i);
            scanf("%d",&A[i]);
        }

    printf("enter the number to be search\n");
    scanf("%d",&x);
    
   int lower=0;
   int higher=n-1;
   int middle=(lower+higher)/2;
   while(lower<=higher)
   {
       if(A[middle]==x)
          {
              printf("%d is found at %d location\n",x,middle+1);
               flag=1;
               break;
          }
         else if(A[middle] < x)
           lower=middle+1;
           else
           higher=middle-1;
           middle=(lower+higher)/2;
           
   }
   if(flag==0)
   printf("%d is not found at any location\n",x);
   
}
