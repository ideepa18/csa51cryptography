#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// English letter frequency table
float english_frequency[ALPHABET_SIZE] = {8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.2, 0.8, 4.0, 2.4,
                                           6.7, 7.5, 1.9, 0.1, 6.0, 6.3, 9.1, 2.8, 1.0, 2.4, 0.2, 2.0, 0.1};

// Function to calculate the frequency of each letter in the ciphertext
void calculateFrequency(char *ciphertext, int *frequency) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            frequency[tolower(ciphertext[i]) - 'a']++;
        }
    }
}

// Function to perform letter frequency attack on a monoalphabetic substitution cipher
void decryptMonoalphabeticSubstitution(char *ciphertext, int top_plaintexts) {
    int frequency[ALPHABET_SIZE] = {0};
    float score[ALPHABET_SIZE] = {0};

    // Calculate frequency of letters in the ciphertext
    calculateFrequency(ciphertext, frequency);

    // Calculate score for each possible shift
    for (int s = 0; s < ALPHABET_SIZE; s++) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            int decrypted_char_index = (i - s + ALPHABET_SIZE) % ALPHABET_SIZE;
            score[s] += frequency[i] * english_frequency[decrypted_char_index];
        }
    }

    // Sort the scores and print top plaintexts
    printf("Top %d possible plaintexts:\n", top_plaintexts);
    for (int i = 0; i < top_plaintexts; i++) {
        float max_score = 0;
        int max_index = 0;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (score[j] > max_score) {
                max_score = score[j];
                max_index = j;
            }
        }
        printf("Plaintext %d (Score %.2f): ", i + 1, max_score);
        for (int k = 0; ciphertext[k] != '\0'; k++) {
            if (isalpha(ciphertext[k])) {
                char decrypted_char = (tolower(ciphertext[k]) - 'a' - max_index + ALPHABET_SIZE) % ALPHABET_SIZE + 'a';
                printf("%c", decrypted_char);
            } else {
                printf("%c", ciphertext[k]);
            }
        }
        printf("\n");
        score[max_index] = 0; // Mark this score as visited to find the next max score
    }
}

int main() {
    char ciphertext[] = "Your ciphertext here"; // Insert the ciphertext here
    int top_plaintexts = 10;

    // Perform letter frequency attack for monoalphabetic substitution cipher
    decryptMonoalphabeticSubstitution(ciphertext, top_plaintexts);

    return 0;
}

