                                            // insertion sort array of employess with name using function//

#include<stdio.h>
#include<string.h>
typedef struct employee
{
    int id;
    float salary;
    char name[20];
}employee;

void read_structure();
void display_structure();
void insertion_sort();

int main()
{
    employee e[90],t;
    int n;
    printf("\nenter how many employees\n");
    scanf("%d",&n);
    read_structure(e,n);
    printf("\nall employees are as follows before sorting\n");
    display_structure(e,n);
    insertion_sort(e,n);
    printf("\nall employees are as follows before sorting\n");
    display_structure(e,n);
    return 1;
}
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
void insertion_sort(employee e[90],int n)
{
    int i,j;
    employee t;

  for(i=1;i<n;i++)
  {
      t=e[i];
      for(j=i-1;j>=0;j--)
      {
          
          if(e[j].id>t.id)           //sorting with the help of name->strcmp(e[j].name,t.name)>0)
            e[j+1]=e[j];
            else
            break;            
     }
     e[j+1]=t;
 }
}
     
