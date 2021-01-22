
                                                              //insertion sort using function//
#include<stdio.h>
void read_array();
void display_array();
void insertion_sort();
int main()
{
    int arr[10];
    int n;
     printf("enter how many numbers u want\n");
    scanf("%d",&n);
    read_array(arr,n);
     printf("\nbefore sorting the array element\n");
     display_array(arr,n);
     insertion_sort(arr,n);
      printf("\nafter sorting the array element\n");
      display_array(arr,n);
    
}


void read_array(int arr[10],int n)
{
    int i;
   for(i=0;i<n;i++)
    {
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
}
void display_array(int arr[10],int n)
{
    int i;
     for(i=0;i<n;i++)
    {
        printf("arr[%d]=%d\n",i,arr[i]);
    }
}

void insertion_sort(int arr[10],int n)
{
    int i,j,key;
for(i=1;i<n;i++)
    {
        key=arr[i];
        for(j=i-1;(j>=0) && (key<arr[j]);j--)
        {
        
            if(arr[j]>key)
             arr[j+1]=arr[j];
             else
             break;
        }
        arr[j+1]=key;
    }
    // printf("total compare=%d\n",cmpcnt);
}
