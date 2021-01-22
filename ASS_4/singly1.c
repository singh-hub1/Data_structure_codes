//singly linked with searching,sorting,reverse using recursion,reverse using loop//

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
      while(temp!=NULL)
      {
          printf("%d\t",temp->data);
           temp=temp->next;
           cnt++;
      }
      printf("\ntotal number of nodes=%d\n",cnt);
}

void sorting(struct node *head)
{
    int temp;
    struct node *ptr,*qtr;
    ptr=head;
    while(ptr->next!=NULL)
    {
        qtr=ptr->next;
         while(qtr!=NULL)
         {
             if(ptr->data > qtr->data)
             {
                 temp=ptr->data;
                 ptr->data=qtr->data;
                 qtr->data=temp;
             }
             qtr=qtr->next;
         }
          ptr=ptr->next;
    }
    display(head);
   
}

void searching(struct node *head)
{
    int i=0,flag,key;
    struct node *temp=head;
    if(temp==NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        printf("enter the number to search in the linked list\n");
        scanf("%d",&key);
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                printf("%d is found at % location\n",key,i+1);
                flag=0;
            }
            else
            {
                flag=1;
            }
            i++;
            temp=temp->next;
        }
        if(flag==1)
        {
            printf("key is not found at any location\n");
        }
    }
    
}
void reverse_recursion(struct node *head)
{
    if(head!=NULL)
    {
        reverse_recursion(head->next);
        printf("%d\t",head->data);
    }
}

void reverse_loop(struct node*head)  //here this is not a good idea//
{
    struct node *p=NULL, *q=NULL,*r=NULL;
    p=head;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
    display(head);
}
    
int main()
{
     struct node *head=NULL;
    int n,ch;
    do
    {
        printf("enter how many nodes u want\n");
        scanf("%d",&n);
    }while(n<=0);

    head=create(head,n);
    do
    {
     printf("\n 1.sorting \n 2.searching \n 3.reverse_recursion\n 4.display\n 5.reverse_loop\n 6.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
         switch(ch)
          {
             case 1: sorting(head);
                        break;
            case 2:  searching(head);
                        break;
            case 3:   reverse_recursion(head);
                        break;
            case 4:  display(head);
                       break;
            case 5: reverse_loop(head);
                        break;
            case 6:return 0;

          }
    }while(ch>0 && ch<=6);
}