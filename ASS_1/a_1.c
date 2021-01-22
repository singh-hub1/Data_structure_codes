//Write a C program to accept and sort n elements in ascending order by using bubble sort.//

#include<stdio.h>
int main()
{
    int arr[10];
    int n,i,j,t;
    int flag=0;
    int cmpcnt=-1,swapcnt=-1;
    printf("enter how many numbers u want\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
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
    printf("\nafter sorting the array element\n");
    for(i=0;i<n;i++)
    {
        printf("arr[%d]=%d\n",i,arr[i]);
    }
    printf("total compare=%d\n",cmpcnt);
    printf("total swapping=%d\n",swapcnt);
    return 1;
}