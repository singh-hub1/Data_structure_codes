//Write a C program to sort a random array of n integers (value of n is accepted from user) by using Insertion Sort algorithm in ascending order//

#include<stdio.h>
#include<stdlib.h>

void generate_random(int a[10],int n)
{
	int i;
	for(i=0;i<n;i++)
	a[i]=rand()%100;
}
void main()
{
	int a[100],n,i,j,temp;
    int t;
	printf("\n Enter size of array:- ");
	scanf("%d",&n);
 
	generate_random(a,n); 

	printf("\n The random array: ");
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
 
	for(i=1;i<n;i++)
	{
          t=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>t)
             a[j+1]=a[j];
             else
             break;
        }
        a[j+1]=t;
	}
 
    printf("\n The sorted array: ");
	for(i=0;i<n;i++)
	printf(" %d ",a[i]);
	printf("\n \n");
}