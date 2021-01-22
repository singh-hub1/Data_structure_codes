/*Write a C program to implement a Singly Circular linked list with following operations create(), display(), search(),length().*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

static int total;

struct node *create(struct node *head,int n)
{
    int i;
    struct node *newnode=NULL,*last=NULL;

    for(i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
          printf("allocation is failed\n");
        else
        {
            printf("enter the node data value in it\n");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            if(head==NULL)
             head=last=newnode;
             else
             {
                 last->next=newnode;
                 last=newnode;
             }
             last->next=head;
        }
    }
    total=n;
    return head;
}

void display(struct node*head)
{
    struct node *temp=head;
    int cnt=0;
    printf("content of linked list are as follows\n");
      while(temp->next!=head)
      {
          printf("%d-->",temp->data);
           temp=temp->next;
           cnt++;
      }
      printf("%d",temp->data);
      printf("\ntotal number of nodes=%d\n",cnt+1); //this is responsible for length// 
}

int search(struct node *head,int x)
{
    int i;
    struct node *temp=head;
  for(i=1;temp->next!=head;i++)
    {
        if(temp->data==x)
            return i;

            temp=temp->next;
    }
    if(temp->data==x)  //this is responsible for last serach node
      return i;
    return 0;
}


int main()
{
    struct node *head=NULL;
    int n,ch,pos,m,x;
    do
    {
        printf("enter how many nodes u want\n");
        scanf("%d",&n);
    }while(n<=0);

    head=create(head,n);
    do
    {
        printf("\n 1.display \n 2.search \n 3.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
         switch(ch)
          {
             case 1:if(head==NULL)
                     printf("singly linked is empty\n");
                    else
                     display(head);
                     break;

             case 2:if(head==NULL)
                     printf("singly linked is empty\n");
                    else
                    {
                        printf("enter the number to be search\n");
                        scanf("%d",&x);
                     m=search(head,x);
                     if(m!=0)
                         printf("given number is present in %d location\n",m);
                     else
                         printf("not found\n");
                    }
                     break;

             case 3: return 0;           
        }
    }while(ch>0 && ch<=3);

}
