//Write a C program to accept and sort n elements in ascending order by using bubble sort using function.//

#include<stdio.h>
void read_array(int[],int);
void display_array(int[],int n);
void bubble_sort(int[],int n);
int main()
{
    int arr[10];
    int n;
    printf("enter how many numbers u want\n");
    scanf("%d",&n);
    read_array(arr,n);
     printf("before sorting array elements\n");
     printf("number are as follows\n");
    display_array(arr,n);
   

    bubble_sort(arr,n);

     printf("\nafter sorting the array element\n");
      printf("number are as follows\n");
    display_array(arr,n);

    return 1;
}

 void read_array(int arr[],int n)
    {
        int i;
      for(i=0;i<n;i++)
      {
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
      }
    }

    void display_array(int arr[],int n)
    {
        int i;
        for(i=0;i<n;i++)
        {
        printf("arr[%d]=%d\n",i,arr[i]);
        }
    }

   void bubble_sort(int arr[],int n)
   {
       int i,j,t,flag=-1,cmpcnt=-1,swapcnt=-1;
      for(i=1;i<n;i++)
       {
        flag=0; //assume no swapping
        for(j=0;j<n-i;j++)
        {
            cmpcnt++;
            if(arr[j]>arr[j+1])
            {
                swapcnt++;
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                flag=1; //swapping happen
            }
        }
        if(flag==0)
         break;
    }
   printf("total compare=%d\n",cmpcnt);
   printf("total swapping=%d\n",swapcnt);
}



