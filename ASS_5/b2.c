#include<stdio.h>
  #include<stdlib.h>
struct node
{
    char data;
    struct node*next;
};

struct node*top=0;


int isempty()
{
    if(top==0)
      return 1;
    else
     return 0;
}


void push()
{
    int x;
    printf("enter the data \n");
    scanf("%d",&x);
    struct node*newnode;
     newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=x;
     newnode->next=top;
     top=newnode;  
}
void pop()
{
    struct node*temp;
    temp=top;
    if(top==NULL)
     printf("underflow condition\n");
     else
     {
        printf("%d",top->data);
        top=top->next; //temp->next;
        free(temp);
     }
     
}


void display()
{
   struct node*temp=top;
    if(top==0)
      printf("underflow condition\n");
    else
    {
        while(temp!=NULL)
         {
             printf("%d\t",temp->data);
             temp=temp->next;
             
         }
    }
}