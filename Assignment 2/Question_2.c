#include <stdio.h>
#include <string.h>

// Global arrays for inventory
char productCodes[4][4] = {"001", "002", "003", "004"};
int quantity[4] = {50, 10, 20, 8};
int price[4] = {100, 200, 300, 150};

// Customer info
char customerName[50];
char customerCNIC[20];

// Cart arrays
int cartIndex[10];
int cartQty[10];
int cartCount = 0;



int main() {
    int choice;
    do {
        printf("\n===== SUPERMARKET MENU =====\n");
        printf("1. Enter Customer Info\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Update Inventory\n");
        printf("5. Display Total Bill\n");
        printf("6. Show Invoice\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch(choice) {
            case 1: enterCustomerInfo(); break;
            case 2: displayInventory(); break;
            case 3: addToCart(); break;
            case 4: updateInventory(); break;
            case 5: displayTotalBill(); break;
            case 6: showInvoice(); break;
            case 7: printf("Exiting system...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 7);
    return 0;
}

void enterCustomerInfo() {
    printf("Enter customer name: ");
    fgets(customerName, 50, stdin);
    customerName[strcspn(customerName, "\n")] = 0;
    printf("Enter CNIC number: ");
    fgets(customerCNIC, 20, stdin);
    customerCNIC[strcspn(customerCNIC, "\n")] = 0;
    printf("Customer info saved!\n");
}

void displayInventory() {
    printf("\n--- INVENTORY ---\n");
    printf("Code\tQuantity\tPrice\n");
    for (int i = 0; i < 4; i++) {
        printf("%s\t%d\t\t%d\n", productCodes[i], quantity[i], price[i]);
    }
}

void addToCart() {
    char code[4];
    int qty;
    int found = -1;

    printf("Enter product code: ");
    scanf("%s", code);
    printf("Enter quantity: ");
    scanf("%d", &qty);

    for (int i = 0; i < 4; i++) {
        if (strcmp(code, productCodes[i]) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Product not found!\n");
    } else if (qty > quantity[found]) {
        printf("Not enough stock available!\n");
    } else {
        cartIndex[cartCount] = found;
        cartQty[cartCount] = qty;
        cartCount++;
        printf("Item added to cart!\n");
    }
}

void updateInventory() {
    for (int i = 0; i < cartCount; i++) {
        int idx = cartIndex[i];
        quantity[idx] -= cartQty[i];
    }
    printf("Inventory updated successfully!\n");
}

void displayTotalBill() {
    int total = 0;
    for (int i = 0; i < cartCount; i++) {
        int idx = cartIndex[i];
        total += price[idx] * cartQty[i];
    }
    printf("\nTotal Bill = Rs. %d\n", total);
}

void showInvoice() {
    int total = 0;
    for (int i = 0; i < cartCount; i++) {
        int idx = cartIndex[i];
        total += price[idx] * cartQty[i];
    }

    printf("\n===== CUSTOMER INVOICE =====\n");
    printf("Name: %s\nCNIC: %s\n", customerName, customerCNIC);
    printf("\nItems Purchased:\n");
    printf("Code\tQty\tPrice\tTotal\n");
    for (int i = 0; i < cartCount; i++) {
        int idx = cartIndex[i];
        printf("%s\t%d\t%d\t%d\n", productCodes[idx], cartQty[i], price[idx], price[idx]*cartQty[i]);
    }
    printf("\nTotal Bill: Rs.%d\n", total);

    char promo[10];
    printf("Enter promocode (or press Enter to skip): ");
    getchar(); // clear buffer
    fgets(promo, 10, stdin);
    promo[strcspn(promo, "\n")] = 0;

    if (strcmp(promo, "Eid2025") == 0) {
        float discount = total * 0.25;
        printf("Promo applied! 25%% discount.\n");
        printf("Final Bill: Rs.%.2f\n", total - discount);
    } else {
        printf("No discount applied.\n");
    }
}
