#include <stdio.h>

// Function to perform Linear Search
void LinearSearch(int arr[], int length, int key)
{
    int i, found = 0, pstn;

    // Traverse the array from beginning to end
    for (i = 0; i < length; i++)
    {
        // Check whether the current element matches the key
        if (key == arr[i])
        {
            // Increment found when the element is found
            found++;

            // Store the index of the found element
            pstn = i;
            break;
        }
    }

    // If the element is found exactly once, display its position
    if (found == 1)
    {
        // Add 1 because array index starts from 0
        printf("The element %d is found at: %d position.", key, (pstn + 1));
    }
    else
    {
        // Element was not found
        printf("Element Not Found!!");
    }
}

int main()
{
    int length, key, i;

    // Take the size of the array from the user
    printf("Enter the size of the array: \n");
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

    // Call Linear Search function
    printf("Linear Search : \n");
    LinearSearch(a, length, key);

    return 0;
}