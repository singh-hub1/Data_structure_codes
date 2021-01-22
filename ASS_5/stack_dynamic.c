                                            //stack using dynamic memory allocation(linked-list) and isempty//
#include<stdio.h>
#include "3.h"

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
            case 1:push();
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