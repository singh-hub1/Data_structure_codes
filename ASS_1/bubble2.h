#include<stdio.h>
#include<string.h>
typedef struct employee
{
    int id;
    float salary;
    char name[20];
}employee;

void read_structure(employee e[90],int n)
{
    int i;
    printf("\nenter %d employess\n",n);
    for(i=0;i<n;i++)
    {
        printf("\nenter id salary name\n");
        scanf("%d %f %s",&e[i].id,&e[i].salary,e[i].name);
    }
}
void display_structure(employee e[90],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%.2f\t%s",e[i].id,e[i].salary,e[i].name);
    }
}
void bubble_sort(employee e[90],int n)
{
    int i,j,swapcnt=0,cmpcnt=0;
    employee t;

  for(i=1;i<n;i++)
  {
      for(j=0;j<n-i;j++)
      {
          cmpcnt++;
          if(strcmp(e[j].name,e[j+1].name)>0)           //sorting with the help of name
           {
             t=e[j];
            e[j]=e[j+1];
            e[j+1]=t;
            swapcnt++;
          }
     }
  }
     printf("\ntotal compare count is %d\n",cmpcnt);
     printf("\ntotal swaping count is %d\n",swapcnt);
}
