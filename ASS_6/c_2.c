/*Write a C program to Implement Dynamic implementation of circular queue of integers with
followingoperation:
a)Initialize()
b) insert()
c)delete()
d) isempty()
e)display()
f) peek()
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node *front=NULL;
struct node*rear=NULL;

void enqueue()
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
       printf("enter the data\n");
       scanf("%d",&newnode->data);
       newnode->next=NULL;
       if(rear==NULL)
        {
            front=rear=newnode;
            rear->next=front;
        }
        else
        {
            rear->next=newnode;
            rear=newnode;
            rear->next=front;
        }
}

void display()
{
    
    struct node*temp;
    if(front==NULL && rear==NULL)
      printf("\nUNDERFLOW CONDITION\n");
    else
    {
        temp=front;
        printf("\ncontent of queue are as follows\n");
        while(temp->next!=front)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

void dequeue()
{
    struct node*temp;
    temp=front;
    if(front==NULL && rear==NULL)
      printf("\nunderflow condition\n");
      else if(front==rear)
      {
          front=rear=NULL;
          free(temp);
      }
    else
    {
        printf("dequeue node:%d\n",front->data);
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void peek()
{
    if(front==NULL && rear==NULL)
     printf("\nunderflow condition\n");
    else
        printf("peek:%d\n",front->data);
}
        
int main()
{
 int ch;
 do
    {
     printf("\n1:enqueue\n2:dequeue\n3:peek\n4:display\n5:exit\n");
     printf("enter the choice\n");
     scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
                    break;
            case 2:dequeue();
                    break;
            case 3:peek();
                    break;
            case 4:display();
                    break;
            case 5:return 0;
                    break;
            default:printf("\ninvalid choice\n");
        }
    } while (ch>0 && ch<=5);
}

