#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// ================== FUNCTION DECLARATIONS & DEFINITIONS ==================

// Function to add a new book
void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Inventory full! Cannot add more books.\n");
        return;
    }

    int newISBN;
    printf("Enter ISBN: ");
    scanf("%d", &newISBN);

    // Check for duplicate ISBN
    for (int i = 0; i < *count; i++) {
        if (isbns[i] == newISBN) {
            printf("Error: Book with this ISBN already exists!\n");
            return;
        }
    }

    isbns[*count] = newISBN;
    printf("Enter title: ");
    getchar();  // clear buffer
    fgets(titles[*count], 50, stdin);
    titles[*count][strcspn(titles[*count], "\n")] = '\0'; // remove newline

    printf("Enter price: ");
    scanf("%f", &prices[*count]);

    printf("Enter quantity: ");
    scanf("%d", &quantities[*count]);

    (*count)++;

    printf("Book added successfully!\n");
}

// Function to process a sale
void processSale(int isbns[], int quantities[], int count) {
    int searchISBN, sold;
    printf("Enter ISBN to sell: ");
    scanf("%d", &searchISBN);

    for (int i = 0; i < count; i++) {
        if (isbns[i] == searchISBN) {
            printf("Enter number of copies sold: ");
            scanf("%d", &sold);

            if (sold > quantities[i]) {
                printf("Error: Not enough stock available!\n");
                return;
            }

            quantities[i] -= sold;
            printf("Sale processed successfully. Remaining stock: %d\n", quantities[i]);
            return;
        }
    }

    printf("Book with ISBN %d not found!\n", searchISBN);
}

// Function to generate low stock report
void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    printf("\n===== Low Stock Report (Quantity < 5) =====\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }
    if (!found)
        printf("All books are sufficiently stocked!\n");
}

// ================== MAIN FUNCTION ==================
int main() {
    int isbns[MAX_BOOKS];
    char titles[MAX_BOOKS][50];
    float prices[MAX_BOOKS];
    int quantities[MAX_BOOKS];
    int count = 0;  // number of books currently stored

    int choice;

    do {
        printf("\n===== Liberty Books Inventory System =====\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, quantities, count);
                break;
            case 3:
                lowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Exiting program... Bye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}
