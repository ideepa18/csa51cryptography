#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <float.h>

#define NUM_LETTERS 26

// English letter frequencies
const float english_frequencies[NUM_LETTERS] = {
    0.0817, 0.0149, 0.0278, 0.0425, 0.127, 0.0223, 0.0202,  // A-G
    0.0609, 0.0697, 0.0015, 0.0077, 0.0403, 0.0241, 0.0675,  // H-N
    0.0751, 0.0193, 0.0009, 0.0599, 0.0633, 0.0906, 0.0276,  // O-U
    0.0098, 0.0236, 0.0015, 0.0197, 0.0007                    // V-Z
};

// Function to count letter frequencies in a string
void count_letter_frequencies(const char *text, int *frequencies) {
    for (int i = 0; text[i]; i++) {
        char c = tolower(text[i]);
        if (isalpha(c)) frequencies[c - 'a']++;
    }
}

// Function to decrypt ciphertext using a given key
void decrypt_with_key(const char *ciphertext, const char *key) {
    for (int i = 0; ciphertext[i]; i++) {
        char c = tolower(ciphertext[i]);
        putchar(isalpha(c) ? key[c - 'a'] : c);
    }
    putchar('\n');
}

int main() {
    char ciphertext[1000];
    char key[NUM_LETTERS + 1] = "", best_key[NUM_LETTERS + 1] = "";
    float min_chi_squared = FLT_MAX;
    int ciphertext_frequencies[NUM_LETTERS] = {0};
    
    printf("Enter ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    
    // Calculate letter frequencies in the ciphertext
    count_letter_frequencies(ciphertext, ciphertext_frequencies);

    // Try all possible keys and calculate chi-squared values
    for (int i = 0; i < NUM_LETTERS; i++) {
        for (int j = 0; j < NUM_LETTERS; j++)
            key[j] = 'a' + (i + j) % NUM_LETTERS;
        key[NUM_LETTERS] = '\0';
        
        float chi_squared = 0;
        for (int j = 0; j < NUM_LETTERS; j++) {
            float diff = ciphertext_frequencies[j] - english_frequencies[j] * strlen(ciphertext);
            chi_squared += diff * diff / (english_frequencies[j] * strlen(ciphertext));
        }
        
        if (chi_squared < min_chi_squared) {
            min_chi_squared = chi_squared;
            strcpy(best_key, key);
        }
    }

    // Decrypt ciphertext using the best key
    printf("Best Key: %s\n", best_key);
    decrypt_with_key(ciphertext, best_key);

    return 0;
}

