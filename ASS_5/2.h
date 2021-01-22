#include<stdio.h>
#define n 5
int stack[n];
int top=-1;


int isfull()
{
    if(top==n-1)
     return 1;
     else
     return 0;
}

int isempty()
{
    if(top==-1)
      return 1;
    else
     return 0;
}

void push()
{
    int x;
    printf("enter the data \n");
    scanf("%d",&x);
    if(top==n-1)
       printf("overflow condition\n");
    else
    {
      top++;
      stack[top]=x;
    }
}

void pop()
{
    int item;
    if(top==-1)
     printf("underflow condition\n");
    else
     {
      item=stack[top];
      top--;
      printf("popped item:%d\n",item);
     }
     
}

void peek()
{
    if(top==-1)
        printf("underflow condition\n");
    else
     printf("peek=%d\n",stack[top]);
}

void display()
{
    int i;
    for(i=top;i>=0;i--)
      {
        printf("%d\t",stack[i]);
      }
}