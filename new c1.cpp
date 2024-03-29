#include <stdio.h>
#include <string.h>

void encrypt(char *message, int shift);
void decrypt(char *message, int shift);

int main() {
    char message[100];
    int shift;

    // Input message from user
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Input shift value
    printf("Enter the shift value (1 to 25): ");
    scanf("%d", &shift);

    // Ensure shift value is within range
    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }

    // Encrypt the message
    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int shift) {
    int i;
    char ch;

    for (i = 0; i < strlen(message); i++) {
        ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z')
            message[i] = 'A' + ((ch - 'A' + shift) % 26);
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z')
            message[i] = 'a' + ((ch - 'a' + shift) % 26);
    }
}

void decrypt(char *message, int shift) {
    int i;
    char ch;

    for (i = 0; i < strlen(message); i++) {
        ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z')
            message[i] = 'A' + ((ch - 'A' - shift + 26) % 26);
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z')
            message[i] = 'a' + ((ch - 'a' - shift + 26) % 26);
    }
}

