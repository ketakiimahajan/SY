// Data Structures IA2 - FOOD ORDERING SYSTEM USING DATA STRUCTURES (used Stack, Queue, List)
// Khushi Parsana - 16014022064 and Ketaki Mahajan - 16014022050

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for menu items
struct Item {
    char name[50];
    float rate;
    struct Item *next;
};

// Structure for items in the cart
struct FoodItem {
    char username[20];
    int qty;
    float price;
    struct FoodItem *next;
    struct Item *item; // Points to the corresponding Item in the menu
};

// Structure for storing orders
struct Order {
    float total;
    char username[20];
    struct Order *next;
};

// Function to display a progress bar
void progressBar(int time) {
    printf("\n=============================================\n");
    printf("  W E L C O M E ,  T O  B R E W  B L I S S\n");
    printf("=============================================\n\n");

    for (int i = 0; i <= time; i++) {
        printf("             [");
        for (int j = 0; j < i; j++) {
            printf("=");
        }
        for (int j = i; j < time; j++) {
            printf("");
        }
        printf("] %d%%\r", (i * 10)); // Progress percentage
        fflush(stdout);
        usleep(500000); // Adjust sleep time based on your requirement
    }
    printf("\n");
}

// Function to display the menu
void displayMenu(struct Item *start) {
    struct Item *temp;
    int i = 1;
    temp = start;
    printf("\n===============================================\n");
    printf("                   M E N U\n");
    printf("===============================================\n");
    printf("Sr. No.\t    Name\t\t\t  Rate\n");
    while (temp != NULL) {
        printf("%-12d%-30s%0.2f\n", i++, temp->name, temp->rate);
        temp = temp->next;
    }
}

// Function to search for a specific item in the menu
struct Item *searchItem(struct Item *start, int n) {
    int i = 1;
    struct Item *temp;
    temp = start;
    while (temp != NULL && i < n) {
        temp = temp->next;
        i++;
    }
    return temp;
}

// Function to add an item to the cart
void pushFoodItem(struct Item *start, struct FoodItem **top, char username[20]) {
    int p, n, q, x, flag = 1;
    float r, s;
    struct FoodItem *temp, *newnode;
    again:
    displayMenu(start);
    if (flag == 0) {
        printf("\nPlease enter a valid choice\n");
    } else {
        printf("\n");
    }
    printf("0. Cancel\n\nEnter sr. no. of item: ");
    scanf("%d", &n);
    if (n != 0) {
        flag = 1;
        newnode = (struct FoodItem *)malloc(sizeof(struct FoodItem));
        if (searchItem(start, n) != NULL) {
            newnode->item = searchItem(start, n);
            strcpy(newnode->username, username);
            printf("\nCurrently ordering: %s\n", newnode->item->name);
            printf("Quantity: ");
            scanf("%d", &q);
            newnode->qty = q;
            r = newnode->item->rate;
            s = q * r;
            newnode->price = s;
            if (*top == NULL) {
                newnode->next = NULL;
                *top = newnode;
            } else {
                newnode->next = *top;
                *top = newnode;
            }
        } else {
            flag = 0;
            printf("\a");
            goto again;
        }
    }
}

// Function to display the items in the cart
void displayCart(struct FoodItem *top, char username[20]) {
    int i = 1;
    float sum = 0;
    struct FoodItem *temp;
    temp = top;
    printf("\n================================================\n");
    printf("                   C A R T\n");
    printf("================================================\n");
    printf("Sr. No.\t  Name\t     Qty\tPrice\n");
    if (top == NULL)
        printf("\nCart is empty\n");
    else {
        while (temp != NULL && !(strcmp(temp->username, username))) {
            printf("%-10d%-12s%-10d%-10.2f\n", i++, temp->item->name, temp->qty, temp->price);
            sum = sum + temp->price;
            temp = temp->next;
        }
        printf("\nTOTAL\t\t\t\t       Rs. %0.2f\n", sum);
    }
}

// Function to remove an item from the cart
void removeFoodItem(struct FoodItem **top, char username[20]) {
    int n;
    struct FoodItem *temp, *prev;
    if (*top == NULL) {
        printf("\nCart is empty\n");
        return;
    }
    displayCart(*top, username);
    printf("\nDo you wish to remove any item? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        printf("\nEnter the serial number of the item to be removed: ");
        scanf("%d", &n);
        if (n == 1) {
            temp = *top;
            *top = (*top)->next;
            free(temp);
        } else {
            temp = *top;
            for (int i = 1; i < n; i++) {
                prev = temp;
                temp = temp->next;
                if (temp == NULL) {
                    printf("\nInvalid choice. Item not found.\n");
                    return;
                }
            }
            prev->next = temp->next;
            free(temp);
        }
        printf("\nItem removed from the cart successfully.\n");
    }
}

// Function to add an order to the list of orders
void enqueueOrder(struct FoodItem *top, struct Order **rear, struct Order **front, char username[20]) {
    int x;
    struct Order *newnode;
    struct FoodItem *temp;
    newnode = (struct Order *)malloc(sizeof(struct Order));
    newnode->total = 0;
    strcpy(newnode->username, username);
    temp = top;
    while (temp != NULL && !(strcmp(temp->username, username))) {
        newnode->total += temp->price;
        temp = temp->next;
    }
    newnode->next = NULL;
    if (*rear == NULL) {
        *front = newnode;
        *rear = newnode;
    } else {
        (*rear)->next = newnode;
        *rear = newnode;
    }
}

// Function to automatically create the menu with predefined items
void autoCreateMenu(struct Item **start) {
    int i, x;
    char names[10][20] = {"Salad", "Soup", "Fries", "Pizza", "Noodles", "Cheesecake", "Blackforest", "Tea", "Coffee", "Water"};
    float rates[10] = {50, 80, 50, 120, 75, 60, 70, 10, 10, 5};
    struct Item *newnode, *temp;
    for (i = 0; i < 10; i++) {
        newnode = (struct Item *)malloc(sizeof(struct Item));
        x = 0;
        while (names[i][x] != '\0') {
            newnode->name[x] = names[i][x];
            x++;
        }
        newnode->name[x] = '\0';
        newnode->next = NULL;
        newnode->rate = rates[i];
        if (*start == NULL)
            *start = newnode;
        else {
            temp = *start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

int main() {
    progressBar(10);

    // Variable declarations and initializations
    struct Item *start = NULL;
    struct FoodItem *top = NULL;
    struct Order *rear = NULL;
    struct Order *front = NULL;
    int choice2;
    char username[20];

    autoCreateMenu(&start); // Adding menu items

    do {
        // Display options to the user
        printf("\n1. Order\n2. View Cart\n3. Remove Item from Cart\n4. Proceed to Checkout\n0. Exit\n\nEnter choice:");
        scanf("%d", &choice2);
        
        // Switch statement for user choices
        switch (choice2) {
            case 1:
                pushFoodItem(start, &top, username);
                break;
            case 2:
                displayCart(top, username);
                removeFoodItem(&top, username);
                break;
            case 3:
                removeFoodItem(&top, username);
                break;
            case 4:
                enqueueOrder(top, &rear, &front, username);
                displayCart(top, username);
                printf("\nOrder placed successfully\n");
                break;
        }
    } while (choice2 != 0 && choice2 != 4);
    return 0;
}
