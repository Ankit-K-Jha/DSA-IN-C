#include <stdio.h>
int main()
{
    int length, i, j, temp;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    int a[length];
    printf("Enter the array elements: \n");
    for (i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array elements are: \n");
    for (i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nSorted Array is: \n");
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
}