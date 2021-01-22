// Write a C program to sort the elements by initializing the array (e.g int A[5] = {10, 20, 35, 23, 12}) using bubble sort//

#include<stdio.h>
int main()
{
    int arr[5]={10,20,35,23,12};
    int n,i,j,t;
    int flag=0;
    int cmpcnt=-1,swapcnt=-1;
    
    for(i=1;i<5;i++)
    {
        flag=0; 
        for(j=0;j<5-i;j++)
        {
            cmpcnt++;
            if(arr[j]>arr[j+1])
            {
                swapcnt++;
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                flag=1; 
            }
        }
        if(flag==0)
         break;
    }
    printf("\nafter sorting the array element\n");
    for(i=0;i<5;i++)
    {
        printf("arr[%d]=%d\n",i,arr[i]);
    }
    printf("total compare=%d\n",cmpcnt);
    printf("total swapping=%d\n",swapcnt);
    return 1;
}