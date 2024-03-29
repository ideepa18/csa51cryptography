#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// English letter frequencies
const float english_frequencies[ALPHABET_SIZE] = {
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
void decrypt_with_key(const char *ciphertext, const char *key, char *plaintext) {
    while (*ciphertext) {
        char c = *ciphertext++;
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            *plaintext++ = key[c - base];
        } else {
            *plaintext++ = c;
        }
    }
    *plaintext = '\0';
}

// Function to calculate chi-squared value
float calculate_chi_squared(const int *observed, const float *expected) {
    float chi_squared = 0.0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        chi_squared += ((observed[i] - expected[i]) *
                        (observed[i] - expected[i])) / expected[i];
    }
    return chi_squared;
}

// Function to swap two integers
void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to swap two characters
void swap_char(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on arrays
void bubble_sort(float *values, char *plaintexts[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                swap_int(&values[j], &values[j + 1]);
                swap_char(plaintexts[j], plaintexts[j + 1]);
            }
        }
    }
}

int main() {
    char ciphertext[1000];
    printf("Enter ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    int ciphertext_frequencies[ALPHABET_SIZE] = {0};
    count_letter_frequencies(ciphertext, ciphertext_frequencies);

    // Mapping between most frequent letters in ciphertext and English alphabet
    const char *most_frequent_ciphertext = "etaoinshrdlcumwfgypbvkjxqz";
    const char *english_alphabet = "abcdefghijklmnopqrstuvwxyz";
    char mapping[ALPHABET_SIZE];

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        mapping[most_frequent_ciphertext[i] - 'a'] = english_alphabet[i];
    }

    // Generate possible plaintexts using the mapping
    char *possible_plaintexts[ALPHABET_SIZE];
    float chi_squared_values[ALPHABET_SIZE];

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char key[ALPHABET_SIZE];
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            key[j] = mapping[(j + i) % ALPHABET_SIZE];
        }
        key[ALPHABET_SIZE] = '\0';

        char *plaintext = (char *)malloc(strlen(ciphertext) + 1);
        decrypt_with_key(ciphertext, key, plaintext);

        int plaintext_frequencies[ALPHABET_SIZE] = {0};
        count_letter_frequencies(plaintext, plaintext_frequencies);

        chi_squared_values[i] = calculate_chi_squared(plaintext_frequencies, english_frequencies);
        possible_plaintexts[i] = plaintext;
    }

    // Sort plaintexts based on chi-squared values
    bubble_sort(chi_squared_values, possible_plaintexts, ALPHABET_SIZE);

    // Display top possible plaintexts
    int num_plaintexts = ALPHABET_SIZE < 10 ? ALPHABET_SIZE : 10;
    printf("\nTop %d possible plaintexts in rough order of likelihood:\n", num_plaintexts);
    for (int i = 0; i < num_plaintexts; i++) {
        printf("%s\n", possible_plaintexts[i]);
        free(possible_plaintexts[i]);  // Free allocated memory
    }

    return 0;
}

