#include <stdio.h>
#include <stdlib.h>

// Node structure of the singly linked list
struct Node
{
    int data;
    struct Node *next;
};

// Insert a new node at the beginning
struct Node *insrtstrt(struct Node *head, int data)
{
    // Allocate memory for new node
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    // Store data in new node
    ptr->data = data;

    // New node points to current head
    ptr->next = head;

    // Make new node the head
    head = ptr;

    return head;
}

// Insert a new node at a given index
struct Node *inbtw(struct Node *head, int index, int data)
{
    // Create new node and pointer p for traversal
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)), *p = head;

    ptr->data = data;

    // Move p to the node just before the required index
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }

    // Connect new node with the next node
    ptr->next = p->next;

    // Connect previous node to the new node
    p->next = ptr;

    return head;
}

// Insert a new node at the end
struct Node *atlast(struct Node *head, int data)
{
    // Create a new node
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)), *p = head;

    ptr->data = data;
    ptr->next = NULL;

    // If linked list is empty, new node becomes head
    if (head == NULL)
        return ptr;

    // Traverse until the last node
    while (p->next != NULL)
    {
        p = p->next;
    }

    // Link last node to the new node
    p->next = ptr;

    return head;
}

// Delete the first node
struct Node *frmstrt(struct Node *head)
{
    // If list is empty, nothing to delete
    if (head == NULL)
        return NULL;

    // Store the current head temporarily
    struct Node *temp = head;

    // Move head to the second node
    head = head->next;

    // Free memory of old head
    free(temp);

    return head;
}

// Delete a node from a given index
struct Node *frmbtw(struct Node *head, int index)
{
    // If list is empty, nothing to delete
    if (head == NULL)
        return NULL;

    struct Node *p = head, *temp;

    // Move p to the node just before the node to be deleted
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }

    // Store the node to be deleted
    temp = p->next;

    // Skip the node to be deleted
    p->next = temp->next;

    // Free memory of deleted node
    free(temp);

    return head;
}

// Delete the last node
struct Node *frmlast(struct Node *head)
{
    // If list is empty, nothing to delete
    if (head == NULL)
        return NULL;

    // If there is only one node
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct Node *p = head;

    // Traverse to the second-last node
    while (p->next->next != NULL)
    {
        p = p->next;
    }

    // Free the last node
    free(p->next);

    // Make second-last node the new last node
    p->next = NULL;

    return head;
}

// Display all elements of the linked list
void display(struct Node *head)
{
    struct Node *temp;

    printf("Linked List is: \n");

    // Traverse the complete linked list
    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d -> ", temp->data);
    }

    printf("NULL\n");
}

int main()
{
    int num, data, i, ch, chr = 1;

    // Initially, linked list is empty
    struct Node *head = NULL, *temp;

    // Allocate memory for the first node
    struct Node *item = (struct Node *)malloc(sizeof(struct Node));

    // Take number of nodes from user
    printf("Enter the Length of Linked List: ");
    scanf("%d", &num);

    // First node becomes the head
    head = item;

    printf("Enter the data one by one\n");

    // Create the initial linked list
    for (i = 0; i < num; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);

        // Store data in current node
        item->data = data;
        item->next = NULL;

        // Create next node if this is not the last node
        if (i < (num - 1))
        {
            struct Node *item2 = (struct Node *)malloc(sizeof(struct Node));

            // Link current node to the newly created node
            item->next = item2;

            // Move item pointer to the new node
            item = item2;
        }
    }

    // Display the initially created linked list
    printf("Linked List is: \n");

    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d -> ", temp->data);
    }

    printf("NULL\n");

    // Continue menu until user chooses to exit
    while (chr == 1)
    {
        printf("Enter your choice: \n1) Insertion\n2) Deletion\n");
        scanf("%d", &ch);

        switch (ch)
        {
        // ================= INSERTION =================
        case 1:
        {
            int choice;

            printf("Where to insert the element: \n");
            printf("1) At begining\n2) In between\n3) At last\n");
            scanf("%d", &choice);

            switch (choice)
            {
            // Insert at beginning
            case 1:
            {
                printf("Enter the data: ");
                scanf("%d", &data);

                head = insrtstrt(head, data);

                display(head);

                printf("Enter 1 for continue or any digit to exit.");
                scanf("%d", &chr);
            }
            break;

            // Insert in between
            case 2:
            {
                int index;

                printf("Enter the index where you want to insert the data: \n");
                scanf("%d", &index);

                printf("Enter the data: ");
                scanf("%d", &data);

                head = inbtw(head, index, data);

                display(head);

                printf("Enter 1 for continue or any digit to exit.");
                scanf("%d", &chr);
            }
            break;

            // Insert at last
            case 3:
            {
                printf("Enter the data: ");
                scanf("%d", &data);

                head = atlast(head, data);

                display(head);

                printf("Enter 1 for continue or any digit to exit.");
                scanf("%d", &chr);
            }
            break;

            // Invalid insertion choice
            default:
            {
                printf("Invalid I");

                printf("Enter 1 for continue or any digit to exit.");
                scanf("%d", &chr);
            }
            }
        }
        break;

        // ================= DELETION =================
        case 2:
        {
            int choice;

            printf("From where to delete the element: \n");
            printf("1) From begining\n2) In between\n3) From last\n");
            scanf("%d", &choice);

            switch (choice)
            {
            // Delete from beginning
            case 1:
            {
                head = frmstrt(head);

                display(head);

                printf("Enter 1 for continue or any digit to exit.");
                scanf("%d", &chr);
            }
            break;

            // Delete from a given index
            case 2:
            {
                int idx;

                printf("Enter the index you want to delete: \n");
                scanf("%d", &idx);

                head = frmbtw(head, idx);

                display(head);

                printf("Enter 1 for continue or any digit to exit.");
                scanf("%d", &chr);
            }
            break;

            // Delete from last
            case 3:
            {
                head = frmlast(head);

                display(head);

                printf("Enter 1 for continue or any digit to exit.");
                scanf("%d", &chr);
            }
            break;

            // Invalid deletion choice
            default:
            {
                printf("Enter 1 for continue or any digit to exit.");
                scanf("%d", &chr);
            }
            break;
            }
        }
        break;

        // Invalid main menu choice
        default:
        {
            printf("Invalid Input!!");

            printf("Enter 1 for continue or any digit to exit.");
            scanf("%d", &chr);
        }
        }
    }

    return 0;
}