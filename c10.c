#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to find the position of a character in the Playfair square
void findPosition(char key[SIZE][SIZE], char letter, int *row, int *col) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (key[i][j] == letter || (letter == 'J' && key[i][j] == 'I')) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt the plaintext message using the Playfair cipher
void encrypt(char key[SIZE][SIZE], char plaintext[]) {
    int len = strlen(plaintext);
    char encrypted[len * 2]; // Double the length to accommodate possible doubled letters and spaces
    int encrypted_index = 0;

    for (int i = 0; i < len; i += 2) {
        char ch1 = plaintext[i];
        char ch2 = (i + 1 < len) ? plaintext[i + 1] : 'X'; // Append 'X' if the last pair has only one character

        // Skip non-alphabetic characters
        if (!isalpha(ch1) || !isalpha(ch2))
            continue;

        int row1, col1, row2, col2;
        findPosition(key, toupper(ch1), &row1, &col1);
        findPosition(key, toupper(ch2), &row2, &col2);

        // Same row
        if (row1 == row2) {
            encrypted[encrypted_index++] = key[row1][(col1 + 1) % SIZE];
            encrypted[encrypted_index++] = key[row2][(col2 + 1) % SIZE];
        }
        // Same column
        else if (col1 == col2) {
            encrypted[encrypted_index++] = key[(row1 + 1) % SIZE][col1];
            encrypted[encrypted_index++] = key[(row2 + 1) % SIZE][col2];
        }
        // Forming a rectangle
        else {
            encrypted[encrypted_index++] = key[row1][col2];
            encrypted[encrypted_index++] = key[row2][col1];
        }
    }

    // Null-terminate the encrypted message
    encrypted[encrypted_index] = '\0';

    // Print the encrypted message
    printf("Encrypted Message: %s\n", encrypted);
}

int main() {
    // Playfair key square (5x5)
    char key[SIZE][SIZE] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };

    // Plaintext message to be encrypted
    char plaintext[] = "Must see you over Cadogan West. Coming at once.";

    // Print the plaintext message
    printf("Plaintext Message: %s\n", plaintext);

    // Encrypt the plaintext message using the Playfair cipher
    encrypt(key, plaintext);

    return 0;
}

