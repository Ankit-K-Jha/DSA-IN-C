#include <stdio.h>

// Function to perform Binary Search
void BinarySearch(int arr[], int length, int key)
{
    int i, mid;
    int end = length - 1;
    int start = 0;
    int found = 0;
    int pstn;

    // Repeat the search until the element is found
    // or the search range becomes invalid
    for (i = 0; i < length; i++)
    {
        // Find the middle element of the current search range
        mid = (start + end) / 2;

        // Check if the middle element is the required key
        if (arr[mid] == key)
        {
            found++;

            // Store position (position starts from 1)
            pstn = mid + 1;

            // Element found, so stop searching
            break;
        }

        // If middle element is greater than key,
        // search in the left half
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }

        // If middle element is smaller than key,
        // search in the right half
        else
        {
            start = mid + 1;
        }
    }

    // Display the result
    if (found)
    {
        printf("%d is found at %d position.", key, pstn);
    }
    else
    {
        printf("Element is not found!!");
    }
}

int main()
{
    int i, length, key;

    // Take the size of the array from the user
    printf("Enter the length of the array: \n");
    scanf("%d", &length);

    // Create an array of the given size
    int a[length];

    // Take array elements as input
    printf("Enter the array elements: \n");
    for (i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }

    // Display the array elements
    printf("\nArray elements are: \n");
    for (i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }

    // Take the element to be searched
    printf("\nEnter the element to search: \n");
    scanf("%d", &key);

    // Perform Binary Search
    printf("Binary Search example: \n");
    BinarySearch(a, length, key);

    return 0;
}