// bubble sort array of employess with name using header file //

#include<stdio.h>
#include"bubble2.h"
void read_structure();
void display_structure();
void bubble_sort();

int main()
{
    employee e[90],t;
    int n;
    printf("\nenter how many employees\n");
    scanf("%d",&n);
    read_structure(e,n);
    printf("\nall employees are as follows before sorting\n");
    display_structure(e,n);
    bubble_sort(e,n);
    printf("\nall employees are as follows before sorting\n");
    display_structure(e,n);
    return 1;
}
