#include <stdio.h>

int main()
{
    int length, i, j, temp, p;

    // Prompt user for total number of elements
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    // Variable-Length Array (VLA) declaration
    int a[length];

    // Read elements into the array
    printf("Enter the array entities: \n");
    for (i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }

    // Display original array before sorting
    printf("\nArray elements are: \n");
    for (i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nSelection sort example: \n");

    // Selection Sort Algorithm
    // The outer loop moves the boundary of the unsorted subarray one step forward
    for (i = 0; i < length - 1; i++)
    {
        // Assume the first unsorted element is the smallest
        p = i;

        // Search the remaining unsorted subarray (index i+1 to length-1) for the minimum element
        for (j = i + 1; j < length; j++)
        {
            if (a[j] < a[p])
            {
                p = j; // Update index of the current smallest element
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (p != i)
        {
            temp = a[p];
            a[p] = a[i];
            a[i] = temp;
        }
    }

    // Print sorted array elements
    for (i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}