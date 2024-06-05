#include <stdio.h>
#include <stdlib.h>

// define structure for node in doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// function to insert node 
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

// function to delete node with specific value 
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* current = head;

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the linked list.\n", key);
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Value %d deleted from the linked list.\n", key);
    return head;
}

// function to search for value
int searchValue(struct Node* head, int key) {
    struct Node* current = head;
    int position = 0;

    while (current != NULL) {
        if (current->data == key) {
            printf("Value %d found at position %d in the linked list.\n", key, position);
            return 1; // value found
        }
        current = current->next;
        position++;
    }

    printf("Value %d not found in the linked list.\n", key);
    return 0; // value not found
}

// function to display linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("\nLinked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("ketaki mahajan / A-3 / 16014022050\nUSING DOUBLY LINKED LIST");
    struct Node* head = NULL;
    int choice, value, searchValueToDelete, searchValueToSearch;

    // Creating the LL
    head = insertAtBeginning(head, 97);
    head = insertAtBeginning(head, 53);
    head = insertAtBeginning(head, 367);
    head = insertAtBeginning(head, 76);
    head = insertAtBeginning(head, 121);
    head = insertAtBeginning(head, 10);

    // display initial LL 
    printf("\n\nInitial ");
    displayList(head);

    // inserting 32
    head = insertAtBeginning(head, 32);

    // displaying LL
    printf("\nDoubly Linked List after inserting 32 at the beginning: ");
    displayList(head);

    // deleting value specified by user
    printf("\nEnter a value to delete from the linked list: ");
    scanf("%d", &searchValueToDelete);
    head = deleteNode(head, searchValueToDelete);

    // displaying LL
    displayList(head);

    // searching for value specified by user
    printf("Enter a value to search in the linked list: ");
    scanf("%d", &searchValueToSearch);
    searchValue(head, searchValueToSearch);

    // free memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
