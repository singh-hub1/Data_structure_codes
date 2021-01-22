//circular singly linked ist with individual operations in it//

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

static int total;
struct node *last;

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
      printf("\ntotal number of nodes=%d\n",cnt+1);
}

struct node *insert_beg(struct node *head)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
      printf("allocation is failed\n");
    else
    {
        printf("enter the value data in it\n");
        scanf("%d",&newnode->data);
        newnode->next=head;
        head=newnode;
        last->next=head;
    }
    total++;
    return head;
}

struct node *insert_end(struct node *head)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
       printf("allocation is failed\n");
    else
    {
         printf("enter the value data in it\n");
        scanf("%d",&newnode->data);
        newnode->next=last->next;
        last->next=newnode;
        last=newnode;
    }
    total++;
    return head;
    
}

struct node *insert_middle(struct node *head,int pos)
{
    struct node *newnode;
     struct node *temp=NULL;
     int i;
     temp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
       printf("allocation is failed\n");
    else
    {
         printf("enter the value data in it\n");
        scanf("%d",&newnode->data);
         for(i=1;i<pos-1;i++)
          temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    total++;
    return head;
    
}

struct node *delete_beg(struct node *head)
{
    struct node *temp;
    temp=head;
    printf("deleted from front:%d\n",temp->data);
    head=head->next;
    last->next=head;
    temp->next=NULL;
    free(temp);
    total--;
    return head;

}

struct node *delete_end(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp->next->next!=head)
      temp=temp->next;
      last=temp;
      temp=temp->next;
      printf("deleted from end:%d\n",temp->data);
      temp->next=NULL;
      last->next=head;
      free(temp);
    total--;
    return head;
}

struct node *delete_middle(struct node *head,int pos)
{
    struct node *temp,*q=NULL;
    int i;

   temp=head;
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
           head=head->next;
           last->next=head;
           temp->next=NULL;
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
