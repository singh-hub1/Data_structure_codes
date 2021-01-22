/*Write a C program to implement a Doubly linked list with following operations create() , display(),
insert(),delete().*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
    struct node*prev;
};

static int total;

struct node *create(struct node *head,int n)
{
    int i;
    struct node*temp;
    struct node*newnode;
    newnode=temp=NULL;
    for(i=1;i<=n;i++)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data part\n");
    scanf("%d",&newnode->data);
    newnode->next=newnode->prev=NULL;
    if(head==NULL)
        head=temp=newnode;
    else
      {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
      }
    }
    total=n;
    return head;
}
struct node *insert(struct node *head,int pos)
{
    int i;
    struct node*temp;
    
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data value\n");
    scanf("%d",&newnode->data);
    newnode->prev=newnode->next=NULL;
    if(pos==1)
    {
        if(head==NULL)
            head=newnode;
            else
            {
                newnode->next=head;
                head->prev=newnode;
                head=newnode;
            }
    }
    else
    {
        temp=head;
        for(i=1;i<pos-1;i++)
            temp=temp->next;
            newnode->next=temp->next;
            newnode->prev=temp;
            if(newnode->next!=NULL)
              (newnode->next)->prev=newnode;
            temp->next=newnode;
    }
    total++;
    return head;
}
struct node*delete(struct node*head,int pos)
{
    int i;
    struct node*temp,*q;
    temp=q=NULL;
    temp=head;
    if(pos==1)
    {
        if(head->next==head)
        {
            printf("deleted element:%d\n",head->data);
            free(head);
            total--;
            return head;
        }
        else
        {
            head=head->next;
            head->prev=NULL;
        }
    }
    else
    {
        q=head;
        for(i=1;i<pos-1;i++)
         q=q->next;
         temp=q->next;
         if(temp->next!=NULL)
           (temp->next)->prev=q;
        q->next=temp->next;
    }
    printf("deleted element:%d\n",temp->data);
    temp->prev=temp->next=NULL;
    free(temp);
    total--;
    return head;
}
void dispaly(struct node*head)
{
    struct node*temp=head;
    printf("content of linked list are as follows\n");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

int count(struct node*head)
{
    int cnt=0;
    struct node*temp=head;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

int main()
{
    struct node*head;
    head=NULL;
    int n,ch;
    int k;
    int pos;
    do
    {
        printf("enter how many nodes u want\n");
        scanf("%d",&n);
    }while(n<=0);
    head=create(head,n);
    do
    {
        printf("\n1:insertion\n2:deletion\n3:display\n4:count\n5:exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the position to be inserted\n");
                    scanf("%d",&pos);
                        if(pos>0 && pos<=total+1)
                        head=insert(head,pos);
                    else
                    {
                    printf("invalid position");
                    }
                    break;
            case 2: if(head==NULL)
                        printf("linked list is empty\n");
                    else
                    {
                        printf("enter the position to be deleted\n");
                        scanf("%d",&pos);
                         if(pos>0 && pos<=total)
                        head=delete(head,pos);
                        else
                        {
                            printf("invalid position\n");
                        }
                        break;
                     }
            case 3:if(head==NULL)
                    printf("linked list is empty\n");
                    else
                        dispaly(head);
                    break;
            case 4:k=count(head);
                        printf("total nodes is %d\n",k);
                        break;
            case 5:return 0;        
        }
    }while(ch>0 &&ch<6);
}