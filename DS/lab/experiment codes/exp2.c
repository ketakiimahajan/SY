#include <stdio.h>
#include <stdlib.h>

// structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert node at beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// function to delete node 
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the linked list.\n", key);
        return head;
    }

    if (prev == NULL) {
        // key first node --> update head
        head = head->next;
    } else {
        // remove node with specified key
        prev->next = current->next;
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

// function to display contents of list
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("ketaki mahajan / A-3 / 16014022050");

    struct Node* head = NULL;
    int choice, value, searchValueToDelete, searchValueToSearch;

    // adding numbers in linked list
    head = insertAtBeginning(head, 97);
    head = insertAtBeginning(head, 53);
    head = insertAtBeginning(head, 367);
    head = insertAtBeginning(head, 76);
    head = insertAtBeginning(head, 121);
    head = insertAtBeginning(head, 10);

    // displaying list
    printf("\nInitial ");
    displayList(head);

    // inserting 32 at beginning
    head = insertAtBeginning(head, 32);

    // displaying list
    printf("Linked List after inserting 32 at the beginning: ");
    displayList(head);

    // deleting value
    printf("Enter a value to delete from the linked list: ");
    scanf("%d", &searchValueToDelete);
    head = deleteNode(head, searchValueToDelete);

    // displaying list
    displayList(head);

    // searching for value specified
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
