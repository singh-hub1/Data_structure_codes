/*Write a C program to Implement Static implementation of circular queue of integers with
followingoperation:
a) Initialize()
b) insert()
c) delete()
d) isempty()
e) isfull()
f) display()
g) peek()
*/

#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue()
{
    int x;
    printf("enter the data\n");
    scanf("%d",&x);
    if(front==-1 && rear==-1)
     {
         front=rear=0;
            queue[rear]=x;
     }
     else if((rear+1)%N==front)
      printf("overflow condition\n");
      else
      {
          rear=(rear+1)%N;
          queue[rear]=x;
      }
      
}
void dequeue()
{
    if(front==-1 && rear==-1)
    printf("underflow condition\n");
    else if(front==rear)
      front=rear=-1;  //only one value then .....
    else
    {
        printf("%d\n",queue[front]);
        front=(front+1)%N;
    }
}

int display()
{
    int i=front;
    int cnt=-0;
     if(front==-1 && rear==-1)
    printf("underflow condition\n");
    else
    {
        while(i!=rear)
        {
            printf("%d\t",queue[i]);
            i=(i+1)%N;
            cnt++;
        }
        printf("%d",queue[i]);  //queue[rear];
    }
    return cnt+1;
}

void peek()
{
    printf("%d\n",queue[front]);
}

int main()
{
    int ch,k;
    do
    {
    printf("\n1:enqueue\n2:dequeue\n3:display\n4:peek\n5:exit\n");
    printf("enter your choice\n");
    scanf("%d",&ch);
      switch(ch)
        {
            case 1:enqueue();
                   break;
            case 2:dequeue();
                   break;
            case 3:k=display();
                   printf("\nlength of circular queue is :%d\n",k+1);
                    break;
            case 4:peek();
                   break;
            case 5:return 0;
            default:printf("your chice is wrong\n");
        }
     } while(ch>0 && ch<=5);

}