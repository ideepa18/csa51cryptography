#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// English letter frequency table
float english_frequency[ALPHABET_SIZE] = {8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.2, 0.8, 4.0, 2.4,
                                           6.7, 7.5, 1.9, 0.1, 6.0, 6.3, 9.1, 2.8, 1.0, 2.4, 0.2, 2.0, 0.1};

// Function to decrypt the ciphertext using additive cipher
void decryptAdditiveCipher(char *ciphertext, int shift) {
    printf("Top 10 possible plaintexts:\n");

    for (int s = 0; s < ALPHABET_SIZE; s++) {
        printf("Shift %d: ", s);
        for (int i = 0; ciphertext[i] != '\0'; i++) {
            if (isalpha(ciphertext[i])) {
                char decrypted_char = tolower(ciphertext[i]) - 'a' - shift + s;
                decrypted_char = (decrypted_char + ALPHABET_SIZE) % ALPHABET_SIZE + 'a';
                printf("%c", decrypted_char);
            } else {
                printf("%c", ciphertext[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    char ciphertext[] = "Your ciphertext here"; // Insert the ciphertext here
    int top_plaintexts = 10;

    // Perform letter frequency attack for each possible shift
    decryptAdditiveCipher(ciphertext, top_plaintexts);

    return 0;
}

