#include<stdio.h>
#include<stdlib.h>
void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&& i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);//left array
      quicksort(number,j+1,last); //right array

   }
}
void generate_random(int a[10],int n)
{
	int i;
	for(i=0;i<n;i++)
	a[i]=rand()%100;
}

int main(){
   int i, n, number[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&n);
   generate_random(number,n);

   printf("elements are as follows: ");
   for(i=0;i<n;i++)
      printf("%d\t",number[i]);

   quicksort(number,0,n-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<n;i++)
      printf(" %d",number[i]);

   return 0;
}