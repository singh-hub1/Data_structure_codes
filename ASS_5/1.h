#include<stdio.h>
#define n 5
typedef struct stack
{
    int data [n];
    int top;
}vishal;

void init(vishal *s)
{
    s->top=-1;
}

int isfull(vishal *s)
{
    if(s->top==n-1)
     return 1;
     else
     return 0;
}

int isempty(vishal *s)
{
    if(s->top==-1)
      return 1;
    else
     return 0;
}

void push(vishal *s)
{
    int x;
    printf("enter the data \n");
    scanf("%d",&x);
      s->data[++s->top]=x;
}

void pop(vishal *s)
{
      s->data[s->top--];
    
}

void peek(vishal *s)
{
    
     printf("peek=%d\n",s->data[s->top]);
}

void display(vishal *s)
{
    int i;
    for(i=s->top;i>=0;i--)
      {
        printf("%d\t",s->data[i]);
      }
}