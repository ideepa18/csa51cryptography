// Code for Affine Caesar Cipher
// Implementation of Affine Caesar Cipher in C

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to encrypt plaintext using Affine Caesar Cipher
void encryptAffineCaesar(char *plaintext, int a, int b) {
    // Code to encrypt plaintext using Affine Caesar Cipher
}

int main() {
    char plaintext[100];
    int a, b;

    // Input plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Input values of 'a' and 'b'
    printf("Enter value of 'a': ");
    scanf("%d", &a);
    printf("Enter value of 'b': ");
    scanf("%d", &b);

    // Validate 'a'
    if (a % ALPHABET_SIZE == 0 || a < 0 || a >= ALPHABET_SIZE) {
        printf("Invalid value of 'a'. 'a' must be in the range 1 to 25 and relatively prime to 26.\n");
        return 1;
    }

    // Encrypt plaintext using Affine Caesar Cipher
    encryptAffineCaesar(plaintext, a, b);

    // Output encrypted ciphertext
    printf("Encrypted ciphertext: %s\n", plaintext);

    return 0;
}

