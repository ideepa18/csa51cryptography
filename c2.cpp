#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to perform monoalphabetic substitution encryption
void encryptMonoalphabetic(char *plaintext, char *key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            int index = tolower(plaintext[i]) - 'a';
            plaintext[i] = islower(plaintext[i]) ? tolower(key[index]) : toupper(key[index]);
        }
    }
}

int main() {
    char plaintext[100];
    char key[ALPHABET_SIZE + 1];

    // Input plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Input key
    printf("Enter key (a-z permutation): ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters
    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Validate key length
    if (strlen(key) != ALPHABET_SIZE) {
        printf("Invalid key. Key must be a permutation of the alphabet (a-z).\n");
        return 1;
    }

    // Encrypt plaintext using monoalphabetic substitution cipher
    encryptMonoalphabetic(plaintext, key);

    // Output encrypted ciphertext
    printf("Encrypted ciphertext: %s\n", plaintext);

    return 0;
}

