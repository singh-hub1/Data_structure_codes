#include<stdio.h>
#include<stdlib.h>
void merge_sort();
void merge();
void generate_random();
void merge_sort(int arr[],int low,int high)
{
   int mid;

   if(low<high)
   {
       mid=(low+high)/2;
       merge_sort(arr,low,mid);
       merge_sort(arr,mid+1,high);
       merge(arr,low,mid,high);
   }
}
void merge(int arr[],int low,int mid,int high)
{
    int t[50],i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while((i<=mid) && (j<=high))
    {
        if(arr[i]>=arr[j])
          t[k++]=arr[j++];
        else
         t[k++]=arr[i++];
    }
    while(i<=mid)
        t[k++]=arr[i++];
    
    while(j<=high)
    t[k++]=arr[j++];

    for(i=low;i<=high;i++)
     arr[i]=t[i];
}
void generate_random(int a[10],int n)
{
	int i;
	for(i=0;i<n;i++)
	a[i]=rand()%100;
}

int main()
{
   int i, n,arr[10];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&n);
    generate_random(arr,n);

    printf("elements are as follows: ");
   for(i=0;i<n;i++)
      printf("%d\t",arr[i]);
  

   merge_sort(arr,0,n-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<n;i++)
      printf(" %d",arr[i]);

   return 0;
}