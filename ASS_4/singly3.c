/*singly linked list with individual operations*/

#include<stdio.h>
#include<stdlib.h>
 struct node
 {
     int data;
     struct node *next;
 };

static int total;
static struct node *last;

struct node *create(struct node *head,int n)
{
    int i;
    struct node *newnode=NULL;

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


void display(struct node *head)
{
    struct node *temp=NULL;
    int cnt=0;
    temp=head;
    while(temp!=last->next) //NULL
     {
         printf("%d\t",temp->data);
         temp=temp->next;
         cnt++;
     }
     printf("\ncount number of linked list is:%d\n",cnt);
}

struct node *insert_beg(struct node *head)
{
    struct node *newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("enter the value\n");
    scanf("%d",&newnode->data);

    if(head==NULL)
    head=newnode;
    else
    {
    newnode->next=head;
    head=newnode;
    }
    return head;
    total++;
}

struct node *insert_end(struct node *head)
{
    struct node *newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("enter the value\n");
    scanf("%d",&newnode->data);
    
    if(head==NULL)
    head=last=newnode;
    else
    {
    last->next=newnode;
    last=newnode;
    }
    return head;
    total++;
}

struct node *insert_middle(struct node *head,int pos)
{
    struct node *newnode=NULL,*temp=NULL;
    int i;
    temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("enter the value\n");
    scanf("%d",&newnode->data);
    
    for(i=1;i<pos-1;i++)
    {
      temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
    total++;
}

struct node *delete_beg(struct node *head)
{
    struct node *temp;
    temp=head;
    printf("delete from front:%d\n",temp->data);
    if(temp->next==NULL)
      {
          head=last=NULL;
          free(head);
          free(last);
      }
    head=head->next;
    temp->next=NULL;
    free(temp);
    total--;    
    return head;

}

struct node *delete_end(struct node *head)
{
    struct node *temp;
    temp=head;
    
    if(temp->next==NULL)
      {
          head=last=NULL;
          free(head);
          free(last);
      }
    else
    {
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        last=temp;
        temp=temp->next;
        printf("delete from front:%d\n",temp->data);
        temp->next=NULL;
        free(temp);
    }
    total--;    
    return head;
}

struct node *delete_middle(struct node *head,int pos)
{
    struct node *temp;
    struct node *q;
    temp=head;
    int i;
    
    if(pos==1)
      {
          if(head->next==last)
          {
               printf("deleted element is %d\n",temp->data);
          head=last=NULL;
          free(head);
          free(last);
         }
         else
         {
              printf("deleted element is %d\n",temp->data);
             head=head->next;
             free(temp);
            
         }
         
      }
    else
    {
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        q=temp->next;
        temp->next=q->next;
        q->next=NULL;
        printf("deleted element is %d\n",q->data);
        free(q);

        
    }
    total--;    
    return head;
}

 int main()
 {
     struct node *head=NULL;
    int n,ch,pos;
    do
    {
        printf("enter how many nodes u want\n");
        scanf("%d",&n);
    }while(n<=0);

    head=create(head,n);
    do
    {
        printf("\n 1.insert at beginning\n 2.insert at end \n 3.insert at middle\n 4.delete from beg\n 5.delete from end\n 6.delete from middle\n 7.display\n 8.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
         switch(ch)
          {
             case 1:head=insert_beg(head);
                    break;
             case 2:head=insert_end(head);
                     break;
            case 3:printf("enter the position to be inserted\n");
                   scanf("%d",&pos);
                   head=insert_middle(head,pos);
                      break;
            case 4: head=delete_beg(head);
                      break;
             case 5: head=delete_end(head);
                      break;
             case 6:printf("enter the position to be deleted\n");
                   scanf("%d",&pos); 
                    head=delete_middle(head,pos);
                      break;
             case 7:display(head);
                     break;
             case 8: return 0;           
        }
    }while(ch>0 && ch<=8);
 }