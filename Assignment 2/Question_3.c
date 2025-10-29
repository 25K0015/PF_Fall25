#include <stdio.h>

#define ROWS 3
#define COLS 3

void updateSector(int grid[ROWS][COLS]);
void querySector(int grid[ROWS][COLS]);
void runDiagnostic(int grid[ROWS][COLS]);

int main() {
    int grid[ROWS][COLS] = {0};
    int choice;
    do {
        printf("\n=== IESCO POWER GRID ===\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: updateSector(grid); break;
            case 2: querySector(grid); break;
            case 3: runDiagnostic(grid); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 4);
    return 0;
}

void updateSector(int grid[ROWS][COLS]) {
    int r, c, bit, val;
    printf("Enter row and col: ");
    scanf("%d %d", &r, &c);
    printf("Enter bit to modify (0=Power,1=Overload,2=Maintenance): ");
    scanf("%d", &bit);
    printf("Enter value (1=Set, 0=Clear): ");
    scanf("%d", &val);

    if (val == 1)
        grid[r][c] |= (1 << bit);
    else
        grid[r][c] &= ~(1 << bit);

    printf("Status updated!\n");
}

void querySector(int grid[ROWS][COLS]) {
    int r, c;
    printf("Enter row and col: ");
    scanf("%d %d", &r, &c);
    int val = grid[r][c];
    printf("\nPower: %s", (val & 1) ? "ON" : "OFF");
    printf("\nOverload: %s", (val & 2) ? "YES" : "NO");
    printf("\nMaintenance: %s\n", (val & 4) ? "REQUIRED" : "NOT REQUIRED");
}

void runDiagnostic(int grid[ROWS][COLS]) {
    int overload = 0, maintenance = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] & 2) overload++;
            if (grid[i][j] & 4) maintenance++;
        }
    printf("Total overloaded sectors: %d\n", overload);
    printf("Total maintenance sectors: %d\n", maintenance);
}
