#include <stdio.h>

int main()
{
    int length, i, j, temp;

    // Read the size of the array
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    // Variable-Length Array (VLA) declaration
    int a[length];

    // Input elements from standard input
    printf("Enter the array elements: \n");
    for (i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }

    // Display original array before sorting
    printf("Array elements are: \n");
    for (i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }

    // Bubble Sort Algorithm
    // Outer loop manages passes (a total of length - 1 passes are sufficient)
    for (i = 0; i < length; i++)
    {
        // Inner loop performs adjacent comparisons.
        // With each pass 'i', the largest element of the unsorted segment bubbles up to index 'length - i - 1'
        for (j = 0; j < length - i - 1; j++)
        {
            // Compare adjacent elements and swap if they are in wrong order
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Output the sorted array
    printf("\nSorted Array is: \n");
    for (i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}