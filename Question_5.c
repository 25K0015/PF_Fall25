#include <stdio.h>
#include <string.h>

void encodeMessage(char msg[]);
void decodeMessage(char msg[]);
void toggleBits(char *ch);

int main() {
    int choice;
    char message[200];

    do {
        printf("\n=== TCS Secure Message Tool ===\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch(choice) {
            case 1:
                printf("Enter message to encode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;
                encodeMessage(message);
                break;
            case 2:
                printf("Enter message to decode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;
                decodeMessage(message);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while(choice != 3);

    return 0;
}

void toggleBits(char *ch) {
    *ch ^= (1 << 1); // toggle 2nd bit
    *ch ^= (1 << 4); // toggle 5th bit
}

void encodeMessage(char msg[]) {
    int len = strlen(msg);
    char reversed[200];
    for (int i = 0; i < len; i++)
        reversed[i] = msg[len - i - 1];
    reversed[len] = '\0';

    for (int i = 0; i < len; i++)
        toggleBits(&reversed[i]);

    printf("Encoded message: %s\n", reversed);
}

void decodeMessage(char msg[]) {
    int len = strlen(msg);
    for (int i = 0; i < len; i++)
        toggleBits(&msg[i]);

    char decoded[200];
    for (int i = 0; i < len; i++)
        decoded[i] = msg[len - i - 1];
    decoded[len] = '\0';

    printf("Decoded message: %s\n", decoded);
}
