// Code for Polyalphabetic Substitution Cipher
// Implementation of Polyalphabetic Substitution Cipher in C

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to encrypt plaintext using Polyalphabetic Substitution Cipher
void encryptPolyalphabetic(char *plaintext, char *key) {
    // Code to encrypt plaintext using Polyalphabetic Substitution Cipher
}

int main() {
    char plaintext[100], key[100];

    // Input plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Input key
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters
    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Encrypt plaintext using Polyalphabetic Substitution Cipher
    encryptPolyalphabetic(plaintext, key);

    // Output encrypted ciphertext
    printf("Encrypted ciphertext: %s\n", plaintext);

    return 0;
}

