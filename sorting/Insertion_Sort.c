#include <stdio.h>

// Utility function to print all elements in the array
void printarray(int *a, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
}

// Function to sort an array using Insertion Sort algorithm
void insertionsort(int *a, int length)
{
    int key, j, i;

    // Start from the second element (index 1) up to the last element
    for (i = 1; i < length; i++)
    {
        key = a[i];   // Element to be inserted into the sorted subarray
        j = i - 1;    // Last index of the sorted subarray

        // Shift elements of a[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        // Place key into its correct sorted position
        a[j + 1] = key;
    }
}

int main()
{
    int length, i;

    // Prompt user for array size
    printf("Enter the length of the array: \n");
    scanf("%d", &length);

    // Variable-Length Array (VLA) declaration
    int a[length];

    // Read elements into the array
    printf("Enter the array elements: \n");
    for (i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }

    // Display elements before sorting
    printf("\nArray elements are: \n");
    printarray(a, length);

    // Perform Insertion Sort in-place
    printf("\nInsertion Sort: \n");
    insertionsort(a, length);

    // Display elements after sorting
    printarray(a, length);

    return 0;
}