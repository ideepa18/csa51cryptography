// Code for Playfair algorithm
// Implementation of Playfair algorithm in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
#define UNUSED 'X'

void prepareKey(char key[], char *cleanKey) {
    int i, j;

    // Convert key to uppercase
    for (i = 0; key[i] != '\0'; i++) {
        key[i] = toupper(key[i]);
    }

    // Remove non-alphabetic characters
    j = 0;
    for (i = 0; key[i] != '\0'; i++) {
        if (isalpha(key[i])) {
            cleanKey[j++] = key[i];
        }
    }
    cleanKey[j] = '\0';
}

void generateMatrix(char key[], char matrix[SIZE][SIZE]) {
    char cleanKey[SIZE * SIZE];
    prepareKey(key, cleanKey);

    // Fill matrix with key
    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (k < strlen(cleanKey)) {
                matrix[i][j] = cleanKey[k++];
            } else {
                matrix[i][j] = UNUSED;
            }
        }
    }
}

void encrypt(char matrix[SIZE][SIZE], char plaintext[]) {
    // Code to encrypt plaintext using Playfair algorithm
}

int main() {
    char key[100], plaintext[100], matrix[SIZE][SIZE];

    // Input key
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    // Generate Playfair matrix
    generateMatrix(key, matrix);

    // Input plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Encrypt plaintext using Playfair algorithm
    encrypt(matrix, plaintext);

    // Output encrypted ciphertext
    printf("Encrypted ciphertext: %s\n", plaintext);

    return 0;
}

