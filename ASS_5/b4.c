//Write a C program to reverse the given number by using static implementation of stack//

#include <stdio.h>
#include <string.h>

#define MAX 100	


int top=-1;
int item;



int stack_string[MAX];


void pushint(int item);


int popint(void);


int isEmpty(void);


int isFull(void);

 
int main()
{
    int str[MAX];
    
    int i,n;
    
    
    printf("enter how many number u want\n");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        pushint(scanf("%d",&str[i]));
        
        
    for(i=0;i<n;i++)
        str[i]=popint();

    printf("Reversed String is: %d\n",str);
    
    return 0;
}
 

void pushint(int item)
{
    
    if(isFull())
    {
        printf("\nStack is FULL !!!\n");
        return;
    }
    
    
    top=top+1;
    stack_string[top]=item;
}
 

 int popint()
{
    if(isEmpty())
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }

    
    item = stack_string[top];
    top=top-1;
    return item;
}
 

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}


int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
