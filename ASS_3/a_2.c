/*Write a C program to accept a search element from user and using binary search method find whether given
element is present or not in the following array. 
A[10] = {1,5,7,12,13,16,17,22,24} */


#include<stdio.h>
#include<stdlib.h>
int main()
{
    int A[10] = {1,5,7,12,13,16,17,22,24};
    int x;
    int flag=0;
    printf("enter the number to be search\n");
    scanf("%d",&x);
    
   int lower=0;
   int higher=10-1;
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
