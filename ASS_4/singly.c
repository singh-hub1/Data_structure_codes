//singly linked list with combined operations//

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

struct node *insert(struct node *head,int pos)
{
    struct node *newnode=NULL, *temp=NULL;
    int i;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
      printf("allocation is failed\n");
    else
    {
        printf("enter the node data value in it\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(pos==1)
        {
            newnode->next=head;
            head=newnode;
        }
        else
        {
            temp=head;
            for(i=1;i<pos-1;i++)
              temp=temp->next;
            newnode->next=temp->next;
            temp->next=newnode;
        }
        total++;
     }
     
        return head;
}

struct node *delete(struct node *head,int pos)
{
    struct node *temp=NULL ,*p=NULL;
    int i;
    temp=head;
    if(pos==1)
         head=head->next;

    else
    {
        p=head;
        for(i=1;i<pos-1;i++)
         p=p->next;
        temp=p->next;
        p->next=temp->next;
    }
    printf("deleted element is %d\n",temp->data);
    temp->next=NULL;
    free(temp);
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
        printf("\n 1.insert \n 2.delete \n 3.display\n 4.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
         switch(ch)
          {
             case 1:printf("enter the choice u want to insert the singly node?\n");
                    scanf("%d",&pos);
                    if(pos>0 && pos<=total+1)
                      head=insert(head,pos);
                    else
                      printf("sry!!..wrong position u entered\n");
                    break;
             case 2:if(head==NULL)
                      printf("singly linked list is empty\n"); 
                    else
                     {
                        printf("enter the position to be delete\n");
                        scanf("%d",&pos);
                        if(pos>0 && pos<=total)
                          head=delete(head,pos);
                        else
                          printf("sry!!..wrong position u entered\n");
                    }
                    break;
             case 3:if(head==NULL)
                     printf("singly linked is empty\n");
                    else
                     display(head);
                     break;
             case 4: return 0;           
        }
    }while(ch>0 && ch<=4);

}
