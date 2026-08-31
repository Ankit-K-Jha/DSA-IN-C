#include <stdio.h>
void printarray(int *a, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", a[i]);
}
void merge(int a[], int low, int high, int mid)
{
    int i = low, j = mid + 1, k = low, b[high - low + 1];
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int x = low; x <= high; x++)
    {
        a[x] = b[x];
    }
}
void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}
int main()
{
    int length, i;
    printf("Enter the length of the array: \n");
    scanf("%d", &length);
    printf("Enter the array elements: \n");
    int a[length];
    for (i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array before sorting: \n");
    printarray(a, length);
    mergesort(a, 0, length - 1);
    printf("\nArray after Merge sort: \n");
    printarray(a, length);
}