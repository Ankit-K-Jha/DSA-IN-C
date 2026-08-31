#include <stdio.h>

// Utility function to print elements of an array
void printarray(int *a, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", a[i]);
}

// Merges two sorted subarrays: a[low..mid] and a[mid+1..high]
void merge(int a[], int low, int high, int mid)
{
    int i = low;      // Starting index for the left subarray
    int j = mid + 1;  // Starting index for the right subarray
    int k = 0;        // Starting index for the temporary buffer 'b'
    int b[high - low + 1]; // Auxiliary array sized to fit the range [low..high]

    // Compare elements from both halves and store the smaller element into 'b'
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    // Copy any remaining elements from the left subarray
    while (i <= mid)
    {
        b[k++] = a[i++];
    }

    // Copy any remaining elements from the right subarray
    while (j <= high)
    {
        b[k++] = a[j++];
    }

    // Transfer the sorted elements from auxiliary array 'b' back into 'a'
    for (int x = 0; x < k; x++)
    {
        a[low + x] = b[x];
    }
}

// Main recursive function that implements Merge Sort
void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        // Calculate the midpoint to divide the array into two halves
        int mid = low + (high - low) / 2; // Prevents potential integer overflow

        // Recursively sort the left half
        mergesort(a, low, mid);

        // Recursively sort the right half
        mergesort(a, mid + 1, high);

        // Merge the two sorted halves
        merge(a, low, high, mid);
    }
}

int main()
{
    int length;

    // Read size of array
    printf("Enter the length of the array: \n");
    scanf("%d", &length);

    // Variable-length array declaration (C99 feature)
    int a[length];

    // Read array elements from standard input
    printf("Enter the array elements: \n");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }

    // Display array before sorting
    printf("Array before sorting: \n");
    printarray(a, length);

    // Run Merge Sort on the full array range [0 .. length - 1]
    mergesort(a, 0, length - 1);

    // Display sorted output
    printf("\nArray after Merge sort: \n");
    printarray(a, length);

    return 0;
}