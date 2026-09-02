#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};


// Function to reverse the linked list
struct Node* reverse(struct Node* head) {

    // prev will store the previous node
    struct Node* prev = NULL;

    // current will point to the current node
    struct Node* current = head;

    // next will temporarily store the next node
    struct Node* next = NULL;

    // Traverse the complete linked list
    while (current != NULL) {

        // Store address of next node
        next = current->next;

        // Reverse the link
        current->next = prev;

        // Move prev one step forward
        prev = current;

        // Move current one step forward
        current = next;
    }

    // prev becomes the new head after reversal
    return prev;
}


// Function to display the linked list
void traversal(struct Node* head) {

    // Traverse until the end of the list
    while (head != NULL) {

        printf("%d -> ", head->data);

        // Move to the next node
        head = head->next;
    }

    printf("NULL\n");
}


// Function to insert a new node at the end
struct Node* insertAtEnd(struct Node* head, int data) {

    // Allocate memory for a new node
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));

    // Store data in the new node
    n->data = data;

    // New node will be the last node
    n->next = NULL;

    // If the list is empty, new node becomes head
    if (head == NULL) {
        return n;
    }

    // Pointer to traverse the list
    struct Node* p = head;

    // Move to the last node
    while (p->next != NULL) {
        p = p->next;
    }

    // Link the last node to the new node
    p->next = n;

    return head;
}


int main() {

    struct Node* head = NULL;

    int n, data;

    // Take the number of nodes from the user
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Check for valid number of nodes
    if (n <= 0) {
        printf("Invalid number of nodes!\n");
        return 0;
    }

    // Take data from the user and insert each node at the end
    for (int i = 0; i < n; i++) {

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        // Insert the entered data at the end of the linked list
        head = insertAtEnd(head, data);
    }


    // Display original linked list
    printf("\nOriginal List: ");
    traversal(head);


    // Reverse the linked list
    head = reverse(head);


    // Display reversed linked list
    printf("Reversed List: ");
    traversal(head);


    return 0;
}