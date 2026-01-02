#include <stdio.h>

#define MENU_SIZE 5 // Define the size of the menu

// Function to display the menu
void displayMenu(char menu[][20], float prices[], int size) {
    printf("Menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i], prices[i]);
    }
}

// Function to calculate the total bill
float calculateBill(int quantities[], float prices[], int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += quantities[i] * prices[i];
    }
    return total;
}

// Main function
int main() {
    // Menu items and their corresponding prices
    char menu[MENU_SIZE][20] = {"Pizza", "Burger", "Pasta", "Salad", "Soda"};
    float prices[MENU_SIZE] = {8.99, 5.49, 7.99, 4.49, 1.99};
    
    int quantities[MENU_SIZE] = {0}; // Array to store quantities for each item
    int orderCount = 0;
    char choice;
    
    // Display menu to the user
    displayMenu(menu, prices, MENU_SIZE);

    // Ask for the order
    printf("\nPlease place your order.\n");
    do {
        int itemNumber, quantity;
        printf("\nEnter the item number (1-%d): ", MENU_SIZE);
        scanf("%d", &itemNumber);
        
        if(itemNumber < 1 || itemNumber > MENU_SIZE) {
            printf("Invalid item number. Please try again.\n");
            continue;
        }

        printf("Enter quantity for %s: ", menu[itemNumber - 1]);
        scanf("%d", &quantity);
        
        quantities[itemNumber - 1] += quantity; // Update the quantity of the item ordered

        printf("Would you like to order another item? (y/n): ");
        getchar(); // to consume the newline left by scanf
        scanf("%c", &choice);
        orderCount++;
        
    } while(choice == 'y' || choice == 'Y');

    // Calculate total bill
    float totalAmount = calculateBill(quantities, prices, MENU_SIZE);
    
    // Display the bill
    printf("\nYour total bill is: $%.2f\n", totalAmount);
    return 0;
}
