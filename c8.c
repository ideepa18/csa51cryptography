#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to generate a cipher sequence based on a keyword
void generateCipherSequence(const char *keyword, char *cipherSequence) {
    int keywordLength = strlen(keyword);
    int index = 0;

    // Copy the keyword to the cipher sequence
    strcpy(cipherSequence, keyword);
    index += keywordLength;

    // Fill the remaining characters with unused letters in normal order
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!strchr(keyword, ch)) {
            cipherSequence[index++] = ch;
        }
    }
}

// Function to encrypt plaintext using the generated cipher sequence
void encrypt(const char *plaintext, const char *cipherSequence, char *ciphertext) {
    int length = strlen(plaintext);

    // Encrypt each character in the plaintext
    for (int i = 0; i < length; i++) {
        char ch = plaintext[i];

        // Encrypt only alphabetic characters
        if (isalpha(ch)) {
            int index;
            if (islower(ch)) {
                index = ch - 'a';
                ciphertext[i] = tolower(cipherSequence[index]);
            } else {
                index = ch - 'A';
                ciphertext[i] = toupper(cipherSequence[index]);
            }
        } else {
            // Leave non-alphabetic characters unchanged
            ciphertext[i] = ch;
        }
    }
    ciphertext[length] = '\0';
}

int main() {
    const char *keyword = "CIPHER";
    char cipherSequence[ALPHABET_SIZE + 1]; // +1 for null terminator
    char plaintext[1000];
    char ciphertext[1000];

    // Generate the cipher sequence based on the keyword
    generateCipherSequence(keyword, cipherSequence);

    // Get plaintext input from the user
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character if present

    // Encrypt the plaintext using the generated cipher sequence
    encrypt(plaintext, cipherSequence, ciphertext);

    // Output the encrypted ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

