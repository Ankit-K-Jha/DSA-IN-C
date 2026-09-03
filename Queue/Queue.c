#include <stdio.h>

#define SIZE 100

// Array to store queue elements
int queue[SIZE];

// Initially, queue is empty
int front = -1;
int rear = -1;

// Function to check whether queue is empty
int isEmpty()
{
    return (front == -1);
}

// Function to check whether queue is full
int isFull()
{
    // In circular queue, next position of rear is front
    return ((rear + 1) % SIZE == front);
}

// Function to insert an element into the queue
void enqueue(int element)
{
    // Check if queue is full
    if (isFull())
    {
        printf("Queue is Full! Cannot insert %d\n", element);
        return;
    }

    // If queue is empty, both front and rear
    // will point to the first position
    if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        // Move rear circularly
        rear = (rear + 1) % SIZE;
    }

    // Insert element at rear
    queue[rear] = element;

    printf("%d inserted successfully.\n", element);
}

// Function to delete an element from the queue
int dequeue()
{
    // Check if queue is empty
    if (isEmpty())
    {
        printf("Queue is Empty! Cannot delete.\n");
        return -1;
    }

    // Store the element present at front
    int element = queue[front];

    // If there is only one element
    if (front == rear)
    {
        // Queue becomes empty
        front = -1;
        rear = -1;
    }
    else
    {
        // Move front circularly
        front = (front + 1) % SIZE;
    }

    printf("%d deleted successfully.\n", element);

    return element;
}

// Function to display all elements of the queue
void display()
{
    // Check if queue is empty
    if (isEmpty())
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue elements: ");

    int i = front;

    // Traverse from front to rear
    while (1)
    {
        printf("%d", queue[i]);

        // Stop when we reach rear
        if (i == rear)
        {
            break;
        }

        printf(" -> ");

        // Move circularly
        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    int length;
    int element;
    int choice;

    // Ask user how many elements they want initially
    printf("Enter the initial number of elements (0-%d): ", SIZE);
    scanf("%d", &length);

    // Validate initial length
    if (length < 0 || length > SIZE)
    {
        printf("Invalid length!\n");
        return 0;
    }

    // Take initial queue elements from user
    printf("Enter %d elements:\n", length);

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &element);
        enqueue(element);
    }

    // Menu-driven program
    while (1)
    {
        printf("\n========== QUEUE MENU ==========\n");
        printf("1. Add element (Enqueue)\n");
        printf("2. Delete element (Dequeue)\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        // Insert element
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &element);

            enqueue(element);
            break;
        // Delete element
        case 2:
            dequeue();
            break;

        // Display queue
        case 3:
            display();
            break;

        // Exit program
        case 4:
            printf("Program terminated.\n");
            return 0;

        // Invalid choice
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}