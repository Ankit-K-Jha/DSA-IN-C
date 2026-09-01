#include <stdio.h>

// Function to print all elements of the array
void printarray(int a[], int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}

// Function to partition the array around a pivot
int partition(int a[], int low, int high)
{
    // Choose the first element as pivot
    // i searches for an element greater than pivot
    // j searches for an element smaller than or equal to pivot
    int i = low + 1, j = high, pivot = a[low], temp;

    do
    {
        // Move i forward while elements are smaller than or equal to pivot
        while (i <= high && a[i] <= pivot)
            i++;

        // Move j backward while elements are greater than pivot
        while (a[j] > pivot)
            j--;

        // If i and j have not crossed, swap the elements
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);

    // Place the pivot in its correct position
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    // Return the pivot's final position
    return j;
}

// Recursive function to perform Quick Sort
void quicksort(int a[], int low, int high)
{
    int partitionindex;

    // Continue sorting as long as there are at least two elements
    if (low < high)
    {
        // Partition the array and get the pivot's position
        partitionindex = partition(a, low, high);

        // Recursively sort the left sub-array
        quicksort(a, low, partitionindex - 1);

        // Recursively sort the right sub-array
        quicksort(a, partitionindex + 1, high);
    }
}

int main()
{
    int len, i;

    // Take the size of the array from the user
    printf("Enter the length of the array: \n");
    scanf("%d", &len);

    // Create an array of the given size
    int a[len];

    // Take array elements as input
    printf("Enter the array quantities: \n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &a[i]);
    }

    // Display the array before sorting
    printf("\nUnsorted Array: \n");
    printarray(a, len);

    // Apply Quick Sort
    quicksort(a, 0, len - 1);

    // Display the sorted array
    printf("\nSorted Array: \n");
    printarray(a, len);

    return 0;
}