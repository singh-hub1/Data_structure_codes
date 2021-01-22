                                  //stack implementation using static(ARRAY) and isempty and isfull with simple array//                            
#include<stdio.h>
#include "2.h" //here i include my own header file
int isfull();
int isempty();
void push();
void pop();
void peek();
void display();
int main()
{
    int ch;
    do
     {
      printf("\n1:push\n2:pop\n3:peek\n4:display\n5:exit\n");
      printf("enter the choice\n");
      scanf("%d",&ch);
        switch(ch)
         {
            case 1:if(isfull())
                    printf("\nstack is overflow\n");
                   else
                    push();
                   break;
            case 2:if(isempty())
                    printf("\nstack is underflow\n");
                   else
                    pop();
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