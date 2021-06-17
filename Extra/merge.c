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

void final_marge(int arr[], int brr[], int crr[], int m, int n)
{
    int i, j, k;
    i = j = k = 0;
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

void merge(int a[100],int lb,int mid,int ub)
{
int i=lb,j=mid+1,k=lb,b[100];
while (i<=mid && j<=ub)
{
if(a[i] <= a[j])
b[k++] = a[i++];
else
b[k++] = a[j++];
}
while (i<=mid)
b[k++] = a[i++];
while (j<=ub)
b[k++] = a[j++];
for (k=lb; k<=ub;k++)
a[k] = b[k];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
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

	mergeSort(arr,0,m-1);
	mergeSort(brr,0,n-1);
	
    final_marge(arr, brr, crr, m, n);
    printf("\n");
   // printf("after merging the array\n");
    printf("\n");
    // for (int i = 0; i < m + n; i++)
    //     printf("%d\n", crr[i]);
    return 0;
}