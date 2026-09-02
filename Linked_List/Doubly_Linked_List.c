#include <stdio.h>
#include <stdlib.h>

// Structure of a node in Doubly Linked List
struct Node
{
    int data;

    // Pointer to the previous node
    struct Node *prev;

    // Pointer to the next node
    struct Node *next;
};

// Head pointer points to the first node
struct Node *head = NULL;


// Function to insert a node at a given position
void insatpstn(int data, int pstn)
{
    // Create a new node dynamically
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    // If inserting at the first position
    if (pstn == 1)
    {
        // New node points to current head
        newnode->next = head;

        // If list is not empty, update previous pointer of head
        if (head != NULL)
        {
            head->prev = newnode;
        }

        // Make new node the new head
        head = newnode;

        printf("Inserted %d at position 1.\n", data);
        return;
    }

    // Pointer used to traverse the list
    struct Node *avail = head;

    // Move avail to the node just before the required position
    for (int i = 1; i < pstn - 1 && avail != NULL; i++)
    {
        avail = avail->next;
    }

    // Position is invalid
    if (avail == NULL)
    {
        printf("Position out of bounds! Cannot insert.\n");

        // Free memory allocated for new node
        free(newnode);
        return;
    }

    // Connect new node with the next node
    newnode->next = avail->next;

    // Connect new node with the previous node
    newnode->prev = avail;

    // If there is a next node, update its previous pointer
    if (avail->next != NULL)
    {
        avail->next->prev = newnode;
    }

    // Connect previous node to the new node
    avail->next = newnode;

    printf("Inserted %d at position %d.\n", data, pstn);
}


// Function to delete a node from a given position
void delatpstn(int pstn)
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("The list is empty! Nothing to delete.\n");
        return;
    }

    // Pointer used to find the node to delete
    struct Node *avail = head;

    // If deleting the first node
    if (pstn == 1)
    {
        // Move head to the next node
        head = avail->next;

        // If list still has nodes, first node's prev should be NULL
        if (head != NULL)
        {
            head->prev = NULL;
        }

        printf("Deleted %d from position 1.\n", avail->data);

        // Free memory of deleted node
        free(avail);
        return;
    }

    // Traverse to the node at the required position
    for (int i = 1; i < pstn && avail != NULL; i++)
    {
        avail = avail->next;
    }

    // Position is invalid
    if (avail == NULL)
    {
        printf("Position out of bounds!Cannot delete.\n");
        return;
    }

    // Connect previous node to the next node
    avail->prev->next = avail->next;

    // If there is a next node, update its prev pointer
    if (avail->next != NULL)
    {
        avail->next->prev = avail->prev;
    }

    printf("Deleted %d from position %d.\n", avail->data, pstn);

    // Free memory of deleted node
    free(avail);
}


// Function to display the doubly linked list
void display()
{
    struct Node *temp = head;

    // Check if list is empty
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Current List: NULL <-> ");

    // Traverse the list from beginning to end
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


int main()
{
    int ch, data, pstn;

    // Infinite loop for menu-driven operations
    while (1)
    {
        printf("\nDoubly Linked List Operations\n");
        printf("1. Insert at Position\n");
        printf("2. Delete from Position\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("NOTE: Postions are assumed from 1 onwards!!\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        // Insert operation
        case 1:

            printf("Enter data to insert: ");
            scanf("%d", &data);

            printf("Enter at which index to be inserted: ");
            scanf("%d", &pstn);

            insatpstn(data, pstn);
            break;


        // Delete operation
        case 2:

            printf("Enter position to delete: ");
            scanf("%d", &pstn);

            delatpstn(pstn);
            break;


        // Display operation
        case 3:

            display();
            break;


        // Exit the program
        case 4:

            printf("Khel Khatam ....!\n");
            exit(0);


        // Handle invalid menu choice
        default:

            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}