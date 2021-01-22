//circular doubly linked list using individual operation//

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
    struct node*prev;
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
     printf("allocation failed\n");
    printf("enter the data part\n");
    scanf("%d",&newnode->data);

    newnode->next=newnode->prev=NULL;
    if(head==NULL)
        head=last=newnode;
    else
      {
        last->next=newnode;
        newnode->prev=last;
        last=newnode;
        last->next=head;
      }
    }
    total=n;
    return head;
}

struct node *insert_beg(struct node *head)
{
    struct node *newnode=NULL;
     newnode=(struct node*)malloc(sizeof(struct node));
     if(newnode==NULL)
     printf("allocation failed\n");

    printf("enter the data part\n");
    scanf("%d",&newnode->data);

    newnode->next=newnode->prev=NULL;

    newnode->next=head;
    newnode->prev=head->prev;
    head->prev=newnode;
    head=newnode;
    last->next=head;

     

     total++;
     
     return head;
}

struct node *insert_end(struct node *head)
{
    struct node *newnode=NULL;
     newnode=(struct node*)malloc(sizeof(struct node));
     if(newnode==NULL)
     printf("allocation failed\n");

    printf("enter the data part\n");
    scanf("%d",&newnode->data);

    newnode->next=newnode->prev=NULL;

    newnode->next=last->next;
    newnode->prev=last;
    last->next=newnode;
    last=newnode;
    head->prev=newnode;

   

    total++;
    return head;
}

struct node *insert_middle(struct node *head,int pos)
{
    struct node *newnode=NULL ,*temp=NULL;
    int i;
    temp=head;
     newnode=(struct node*)malloc(sizeof(struct node));
     if(newnode==NULL)
     printf("allocation failed\n");

    printf("enter the data part\n");
    scanf("%d",&newnode->data);

    newnode->next=newnode->prev=NULL;
     
     for(i=1;i<pos-1;i++)
       temp=temp->next;

       newnode->prev=temp;
       newnode->next=temp->next;
       (temp->next)->prev=newnode;
       temp->next=newnode;

     printf("%d\n",head->prev->data);
      printf("%d\n",last->next->data);
        
         total++;
         return head;
}

struct node *delete_beg(struct node *head)
{
    struct node *temp=NULL;
    temp=head;
    printf("delete from front:%d\n",temp->data);
    head=head->next;
    head->prev=temp->prev;
    last->next=head;

    temp->next=temp->prev=NULL;
    free(temp);

    total--;
    return head;
    
}


struct node *delete_end(struct node *head)
{
    struct node *temp=NULL;
    temp=head;
    while((temp->next)->next!=head)
       temp=temp->next;
    last=temp;
    temp=temp->next;
    printf("deleted element:%d\n",temp->data);
    last->next=head;
    head->prev=last;

    temp->next=temp->prev=NULL;
    free(temp);

    total--;
    return head;
    
}

struct node *delete_middle(struct node *head,int pos)
{
    struct node *temp=NULL;
    struct node *q;
    temp=head;
    int i;
    
    if(pos==1)
    {
        if(head->next==last->prev)
        {
            printf("deleted element is %d\n",temp->data);
            head=temp=last=NULL;
            free(temp);
            free(head);
            free(last);
        }
        else
        {
             head=head->next;
             head->prev=temp->prev;
             last->next=head;
             temp->next=temp->prev=NULL;
             free(temp);
        }
    }
    else
    {
       for(i=1;i<pos-1;i++)
           temp=temp->next;
        q=temp->next;
        temp->next=q->next;
        (q->next)->prev=temp;
        q->next=q->prev=NULL;
        free(q);
    }
     total--;
    return head;
    
}

void display(struct node *head)
{
    struct node *temp=head;
    while(temp->next!=head)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
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
