                                  //stack implementation using static(ARRAY) and isempty and isfull with structure //                            
#include<stdio.h>
#include "1.h" //here i include my own header file
int isfull();
int isempty();
void push();
void pop();
void peek();
void display();

int main()
{
    int ch;
    vishal s1;
    init(&s1);
    do
     {
      printf("\n1:push\n2:pop\n3:peek\n4:display\n5:exit\n");
      printf("enter the choice\n");
      scanf("%d",&ch);
        switch(ch)
         {
            case 1:if(isfull(&s1))
                    printf("\nstack is overflow\n");
                   else
                    push(&s1);
                   break;
            case 2:if(isempty(&s1))
                    printf("\nstack is underflow\n");
                   else
                    pop(&s1);
                   break;
            case 3:peek(&s1);
                   break;
            case 4:display(&s1);
                   break;
            case 5:return 0;
                   break;
            default:printf("\ninvalid choice\n");
        }
    } while (ch>0 && ch<=5);
}