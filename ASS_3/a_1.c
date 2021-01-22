//Write a C program to accept the following array and find ‘x=26’ is whether present in array or not.A[7] = {11, 5, 45, 26, 12,34,19}//

#include<stdio.h>

int main()
{
    int a[7]={11, 5, 45, 26, 12,34,19},i,x,f=0;

    x=26;

    for(i=0;i<7;i++)
    {
        if(a[i]==x)
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
