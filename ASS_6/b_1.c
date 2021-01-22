/*Write a C program to Implement Dynamic implementation of Queue of integers with following
operation:
a) Initialize()
b) insert()
c) delete()
d) isempty()
e) display()
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
       if(front==NULL && rear==NULL)
        front=rear=newnode;
        else
        {
            rear->next=newnode;
            rear=newnode;
        }
}

int display()
{
    int cnt=0;
    struct node*temp;
    if(front==NULL && rear==NULL)
      printf("\nUNDERFLOW CONDITION\n");
    else
    {
        temp=front;
        printf("\ncontent of queue are as follows\n");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
            cnt++;
        }
    }
    return cnt;
}

void dequeue()
{
    struct node*temp;
    temp=front;
    if(front==NULL && rear==NULL)
      printf("\nunderflow condition\n");
    else
    {
        printf("dequeue node:%d\n",front->data);
        front=front->next;
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
 int ch,k;
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
            case 4:k=display();
                    printf("\nlength of queue=%d\n",k);
                    break;
            case 5:return 0;
                    break;
            default:printf("\ninvalid choice\n");
        }
    } while (ch>0 && ch<=5);
}
