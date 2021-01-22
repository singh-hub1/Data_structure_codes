// bubble sort array of employess//

#include<stdio.h>
typedef struct employee
{
    int id;
    float salary;
    char name[20];
}employee;
int main()
{
    employee e[90],t;
    int n,i,j,swapcnt=0,cmpcnt=0;
    printf("\nenter how many employees\n");
    scanf("%d",&n);
    printf("\nenter %d employess\n",n);
    for(i=0;i<n;i++)
    {
        printf("\nenter id salary name\n");
        scanf("%d %f %s",&e[i].id,&e[i].salary,e[i].name);
    }
    printf("\nall employees are as follows before sorting\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%.2f\t%s",e[i].id,e[i].salary,e[i].name);
    }

  for(i=1;i<n;i++)
  {
      for(j=0;j<n-i;j++)
      {
          cmpcnt++;
          if(e[j].id>e[j+1].id) //using id sort
           {
             t=e[j];
            e[j]=e[j+1];
            e[j+1]=t;
            swapcnt++;
          }
     }
  }
   printf("\nall employees are as follows after sorting\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%.2f\t%s",e[i].id,e[i].salary,e[i].name);
    }
    printf("\ntotal compare count is %d\n",cmpcnt);
     printf("\ntotal swaping count is %d\n",swapcnt);
return 1;
}
