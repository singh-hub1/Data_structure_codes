#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head1,*head2;

struct node *create();
void display();
static int z;
void intersect_node();
int main()
{
    int m,n;
    head1=head2=NULL;
    printf("enter the first linked list set\n");
    scanf("%d",&n);
    head1=create(head1,n);
    printf("content of first linked list\n");
        display(head1);

    printf("\nenter the second linked list set\n");
    scanf("%d",&m);
    head2=create(head2,m);
      printf("content of second linked list\n");
        display(head2);

z=m+n;
intersect_node(head1,head2);
}
struct node*create(struct node*head1,int x)
{
    struct node *temp,*newnode;
    int i;
    for(i=1;i<=x;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head1==NULL)
            head1=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head1;
    
}

void display(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head=head->next;
    }
}

void intersect_node(struct node*head1,struct node*head2)
{ 
int i;
struct node*temp1,*temp2;
temp1=head1;
temp2=head2;
   while (temp1 != NULL && temp2 != NULL)
   {
       if(temp1->data==temp2->data)
           printf("\nintersection:%d\n",temp1->data);
      
       temp1=temp1->next;
       temp2=temp2->next;
   }
   
}