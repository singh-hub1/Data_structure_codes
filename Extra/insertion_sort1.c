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

void insertionsort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i <= n - 1; i++) //number of passes
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
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
    insertionsort(arr, n);
    printf("\n");
    printarray(arr, n);
}