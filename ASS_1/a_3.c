                    //Write a C program to accept and sort n elements in ascending order by using insertion sort.//


#include<stdio.h>
int main()
{
    int arr[10];
    int n,i,j,t;
    int cmpcnt=0;
    printf("enter how many numbers u want\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++)
    {
        t=arr[i];
        for(j=i-1;j>=0;j--)
        {
        // cmpcnt++;
            if(arr[j]>t)
             arr[j+1]=arr[j];
             else
             break;
        }
        arr[j+1]=t;
    }
    printf("\nafter sorting the array element\n");
    for(i=0;i<n;i++)
    {
        printf("arr[%d]=%d\n",i,arr[i]);
    }
   // printf("total compare=%d\n",cmpcnt);

    return 1;
}