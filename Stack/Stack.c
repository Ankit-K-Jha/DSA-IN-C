#include <stdio.h>

int top = -1;

// Function declarations
void push(int stack[], int size, int value);
int pop(int stack[]);
void display(int stack[]);

int main() {

    int size, n, val, i, to_pop;

    // Input the size of the stack
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    // Stack array must be declared after getting the size
    int stack[size];

    // Input number of elements to push
    // Number of elements cannot be greater than stack size
    do {
        printf("How many elements do you want to push? ");
        scanf("%d", &n);

        if (n < 0 || n > size) {
            printf("Invalid input! Enter a number between 0 and %d.\n", size);
        }

    } while (n < 0 || n > size);

    // Push elements into the stack
    for (i = 0; i < n; i++) {

        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);

        push(stack, size, val);
    }

    // Display stack after push operations
    display(stack);

    // Input number of elements to pop
    // Number of elements to pop cannot be greater
    // than the current number of elements
    do {
        printf("\nHow many elements do you want to pop? ");
        scanf("%d", &to_pop);

        if (to_pop < 0 || to_pop > top + 1) {
            printf("Invalid input! You can pop between 0 and %d elements.\n",
                   top + 1);
        }

    } while (to_pop < 0 || to_pop > top + 1);

    // Pop elements from the stack
    for (i = 0; i < to_pop; i++) {

        int popped = pop(stack);

        printf("Popped element: %d\n", popped);
    }

    // Display stack after pop operations
    display(stack);

    return 0;
}


// Push an element into the stack
void push(int stack[], int size, int value) {

    // Check if the stack is full
    if (top == size - 1) {

        printf("Stack Overflow! Cannot push %d\n", value);

    } else {

        top++;
        stack[top] = value;

        printf("%d pushed into stack.\n", value);
    }
}


// Remove and return the top element
int pop(int stack[]) {

    // Check if the stack is empty
    if (top == -1) {

        printf("Stack Underflow!\n");
        return -1;
    }

    int val = stack[top];
    top--;

    return val;
}


// Display all elements of the stack
void display(int stack[]) {

    if (top == -1) {

        printf("Stack is empty.\n");

    } else {

        printf("Current Stack elements: ");

        // Display elements from bottom to top
        for (int i = 0; i <= top; i++) {
            printf("-> %d ", stack[i]);
        }

        printf("\n");
    }
}