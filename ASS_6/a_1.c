/*Write a C program to Implement Static implementation of Queue of integers with following
operation:
a) Initialize()
b) insert()
c) delete()
d) isempty()
e) isfull()
f) display()
g) peek
*/


#include<stdio.h>
#include<stdlib.h>
#define n 5

int queue[n];
int rear;
int front=-1;
int rear=-1;


void enqueue()
{
    int x;
    if(rear==n-1)
      printf("overflow\n");

       printf("enter the data\n");
         scanf("%d",&x);

    if(front==-1 && rear==-1)
      {
          front=rear=0;
          queue[rear]=x;
      }
      else
      {
          rear++;
          queue[rear]=x;
      }
}

void dequeue()
{
    if(front==-1 && rear==-1)
     printf("\nunderflow condition\n");
    else if(front==rear)
     front=rear=-1;
     else
     {
         printf("%d\n",queue[front]);
         front++;
     }
}

void display()
{
    int i,cnt=0;
    if(front==-1 && rear==-1)
      printf("\nunderflow condition\n");
    else
    {
        for(i=front;i<rear+1;i++) //i<=rear
          {
              printf("%d\t",queue[i]);
              
          }
    }
}

void peek()
{
    if(front==-1 && rear==-1)
      printf("\nunderflow condition\n");
      else
      printf("peek=%d\n",queue[front]);
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

