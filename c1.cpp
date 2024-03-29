#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to encrypt plaintext using Caesar cipher
void encryptCaesar(char *plaintext, int key) {
    for (int i = 0; plaintext[i] != '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            plaintext[i] = (plaintext[i] - base + key) % ALPHABET_SIZE + base;
        }
    }
}

int main() {
    char plaintext[100];
    int key;

    // Input plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Input key
    printf("Enter key (1-25): ");
    scanf("%d", &key);

    // Validate key
    if (key < 1 || key > 25) {
        printf("Invalid key. Key must be in the range 1-25.\n");
        return 1;
    }

    // Encrypt plaintext using Caesar cipher
    encryptCaesar(plaintext, key);

    // Output encrypted ciphertext
    printf("Encrypted ciphertext: %s\n", plaintext);

    return 0;
}

