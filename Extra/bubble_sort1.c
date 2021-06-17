#include <stdio.h>

void getarray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
}
void printarray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("arr[%d]=%d", i, arr[i]);
        printf("\n");
    }
}

void bubblesort(int arr[], int n)
{
    int i, j, temp;
    int flag;//only for adaptitive purpose
    for (i = 0; i < n - 1; i++) //number of passes
    {
        flag=1;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag=0;
            }
        }
        if(flag)
        return;
    }
}
int main()
{
    int arr[10], n;
    printf("enter how many number u want in the array\n");
    scanf("%d", &n);
    getarray(arr, n);
    printf("\n");
    printarray(arr, n);
    bubblesort(arr, n);
    printf("\n");
    printarray(arr, n);
}