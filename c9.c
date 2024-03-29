#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to find the position of a character in the Playfair square
void findPosition(char key[SIZE][SIZE], char letter, int *row, int *col) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (key[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to decrypt the Playfair-encoded message
void decrypt(char key[SIZE][SIZE], char message[]) {
    int row1, col1, row2, col2;
    int len = strlen(message);

    for (int i = 0; i < len; i += 2) {
        char ch1 = message[i];
        char ch2 = message[i + 1];

        // Skip non-alphabetic characters
        if (!isalpha(ch1) || !isalpha(ch2))
            continue;

        // Find positions of characters in the Playfair square
        findPosition(key, ch1, &row1, &col1);
        findPosition(key, ch2, &row2, &col2);

        // Decrypt the pair of characters
        if (row1 == row2) {
            printf("%c%c", key[row1][(col1 - 1 + SIZE) % SIZE], key[row2][(col2 - 1 + SIZE) % SIZE]);
        } else if (col1 == col2) {
            printf("%c%c", key[(row1 - 1 + SIZE) % SIZE][col1], key[(row2 - 1 + SIZE) % SIZE][col2]);
        } else {
            printf("%c%c", key[row1][col2], key[row2][col1]);
        }
    }
}

int main() {
    // Playfair key square (5x5)
    char key[SIZE][SIZE] = {
        {'K', 'X', 'J', 'E', 'Y'},
        {'U', 'R', 'E', 'B', 'Z'},
        {'W', 'H', 'T', 'F', 'S'},
        {'G', 'O', 'Y', 'C', 'A'},
        {'P', 'L', 'Q', 'M', 'N'}
    };

    // Encrypted message received at the Australian wireless station
    char message[] = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";

    printf("Encrypted Message: %s\n", message);
    printf("Decrypted Message: ");

    // Decrypt the message
    decrypt(key, message);

    printf("\n");

    return 0;
}

