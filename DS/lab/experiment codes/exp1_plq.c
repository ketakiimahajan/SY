#include <stdio.h>

// Function to display the elements of an array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert a number at a specified location in an array
int insertElement(int arr[], int size, int location, int value) {
    if (location < 0 || location > size) {
        printf("Invalid location for insertion.\n");
        return size;
    }

    // Shift elements to the right to make space for the new value
    for (int i = size; i > location; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new value at the specified location
    arr[location] = value;
    return size + 1; // Increase the size of the array
}

// Function to delete an element from a specified location in an array
int deleteElement(int arr[], int size, int location) {
    if (location < 0 || location >= size) {
        printf("Invalid location for deletion.\n");
        return size;
    }

    // Shift elements to the left to overwrite the deleted value
    for (int i = location; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1; // Decrease the size of the array
}

int main() {
    printf("ketaki mahajan / A-3 / 16014022050");
    int arr[100]; // Assuming a maximum array size of 100
    int size, choice, location, value;

    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    displayArray(arr, size);

    do {
        printf("\nMenu:\n");
        printf("1. Insert a number\n");
        printf("2. Delete a number\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the location where you want to insert: ");
                scanf("%d", &location);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                size = insertElement(arr, size, location, value);
                displayArray(arr, size);
                break;
            case 2:
                printf("Enter the location of the element you want to delete: ");
                scanf("%d", &location);
                size = deleteElement(arr, size, location);
                displayArray(arr, size);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
