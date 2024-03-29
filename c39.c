#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_LETTERS 26
#define MAX_PLAINTEXTS 10

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
void decrypt_with_key(const char *ciphertext, int shift) {
    printf("Shift: %d, Plaintext: ", shift);
    for (int i = 0; ciphertext[i]; i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char decrypted = ((c - base) - shift + NUM_LETTERS) % NUM_LETTERS + base;
            putchar(decrypted);
        } else {
            putchar(c);
        }
    }
    putchar('\n');
}

// Function to calculate chi-squared value
float calculate_chi_squared(const int *observed, const float *expected) {
    float chi_squared = 0.0;
    for (int i = 0; i < NUM_LETTERS; i++) {
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

// Function to swap two strings
void swap_str(char *a, char *b) {
    char temp[1000];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

// Function to perform bubble sort on arrays
void bubble_sort(float *values, char **plaintexts, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                swap_int(&values[j], &values[j + 1]);
                swap_str(plaintexts[j], plaintexts[j + 1]);
            }
        }
    }
}

int main() {
    char ciphertext[1000];
    printf("Enter ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    int ciphertext_frequencies[NUM_LETTERS] = {0};
    count_letter_frequencies(ciphertext, ciphertext_frequencies);

    // Try all possible shift values and calculate chi-squared values
    float chi_squared_values[NUM_LETTERS];
    char *possible_plaintexts[NUM_LETTERS];
    for (int shift = 0; shift < NUM_LETTERS; shift++) {
        char plaintext[strlen(ciphertext) + 1];
        for (int i = 0; ciphertext[i]; i++) {
            char c = ciphertext[i];
            if (isalpha(c)) {
                char base = islower(c) ? 'a' : 'A';
                char decrypted = ((c - base) - shift + NUM_LETTERS) % NUM_LETTERS + base;
                plaintext[i] = decrypted;
            } else {
                plaintext[i] = c;
            }
        }
        plaintext[strlen(ciphertext)] = '\0';

        int plaintext_frequencies[NUM_LETTERS] = {0};
        count_letter_frequencies(plaintext, plaintext_frequencies);

        chi_squared_values[shift] = calculate_chi_squared(plaintext_frequencies, english_frequencies);
        possible_plaintexts[shift] = strdup(plaintext);
    }

    // Sort plaintexts based on chi-squared values
    bubble_sort(chi_squared_values, possible_plaintexts, NUM_LETTERS);

    // Display top possible plaintexts
    int num_plaintexts = (NUM_LETTERS < MAX_PLAINTEXTS) ? NUM_LETTERS : MAX_PLAINTEXTS;
    printf("\nTop %d possible plaintexts in rough order of likelihood:\n", num_plaintexts);
    for (int i = 0; i < num_plaintexts; i++) {
        printf("Chi-squared value: %.4f, Plaintext: %s\n", chi_squared_values[i], possible_plaintexts[i]);
        free(possible_plaintexts[i]); // Free allocated memory for plaintexts
    }

    return 0;
}

