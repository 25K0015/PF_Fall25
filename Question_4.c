#include <stdio.h>
#define MAX 5

int top = -1;
int stack[MAX];

void push();
void pop();
void peek();
void display();

int main() {
    int choice;
    do {
        printf("\n=== STACK MENU ===\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);
    return 0;
}

void push() {
    int val;
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else {
        printf("Enter value: ");
        scanf("%d", &val);
        stack[++top] = val;
        printf("Pushed %d\n", val);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("Popped %d\n", stack[top--]);
}

void peek() {
    if (top == -1)
        printf("Stack is empty!\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void display() {
    if (top == -1)
        printf("Stack is empty!\n");
    else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
