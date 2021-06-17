#include <stdio.h>
//if u have 2 array 
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void mergeSort(int arr[], int brr[], int crr[], int m, int n)
{
    int i=0, j=0, k=0;
    while (i < m && j < n)
    {
        if (arr[i] < brr[j])
        {
            crr[k] = arr[i];
            k++;
            i++;
        }

        else
        {
            crr[k] = brr[j];
            k++;
            j++;
        }
    }

    while (i < m)
    {
        crr[k] = arr[i];
        k++;
        i++;
    }

    while (j < n)
    {
        crr[k] = brr[j];
        k++;
        j++;
    }
     printArray(crr,m+n);
}

void getarray(int A[], int x)
{
    int i;
    for (i = 0; i < x; i++)
    {
        printf("A[%d]=", i);
        scanf("%d", &A[i]);
    }
}

int main()
{
    int arr[10];
    int brr[10];

    int m, n;
    printf("enter how many number u want in first array\n");
    scanf("%d", &m);
    getarray(arr, m);
    printArray(arr, m);

    printf("\n");

    printf("enter how many number u want in second array\n");
    scanf("%d", &n);
    getarray(brr, n);
    printArray(brr, n);

    printf("\n");
    int crr[m + n];

    mergeSort(arr, brr, crr, m, n);
    printf("\n");
   // printf("after merging the array\n");
    printf("\n");
    // for (int i = 0; i < m + n; i++)
    //     printf("%d\n", crr[i]);
    return 0;
}