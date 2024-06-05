#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1; // Element not found
}

int main() {
    printf("ketaki mahajan / A-3 / 16014022050");
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 100;

    int result = linearSearch(arr, n, x);
    if (result == -1) {
        printf("\nElement is not present in the array.");
    } else {
        printf("\n\nElement is present at index %d", result);
    }
    return 0;
}
