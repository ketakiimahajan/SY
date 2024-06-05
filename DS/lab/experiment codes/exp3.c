#include <stdio.h>
#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

// push
void push(int element) {
    if (top >= MAX_SIZE - 1) {
        printf("\nStack Overflow! Cannot push element %d.\n", element);
    } else {
        stack[++top] = element;
        printf("Pushed %d onto the stack.\n", element);
    }
}

// pop
void pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top--]);
    }
}

// display
void display() {
    if (top == -1) {
        printf("\nStack is empty.\n\n");
    } else {
        printf("\nStack contents: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("ketaki mahajan / A-3 / 16014022050\n\n");
    
    push(21);
    push(34);
    push(45);
    push(21);
    push(60);
    push(100);
    
    display();
    
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    
    display();
    
    push(21);
    push(34);
    push(45);
    push(21);
    push(60);
    
    display();

    return 0;
}
