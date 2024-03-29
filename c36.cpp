#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Encrypt function for affine Caesar cipher
char encrypt(char plain, int a, int b) {
    if (isalpha(plain)) {
        char base = islower(plain) ? 'a' : 'A';
        return ((a * (plain - base) + b) % 26) + base;
    }
    return plain; // If not an alphabet character, return unchanged
}

// Decrypt function for affine Caesar cipher
char decrypt(char cipher, int a, int b) {
    if (isalpha(cipher)) {
        char base = islower(cipher) ? 'a' : 'A';
        int inverse_a = 0;
        while ((a * inverse_a) % 26 != 1) {
            inverse_a++;
        }
        return (inverse_a * ((cipher - base - b + 26) % 26) % 26) + base;
    }
    return cipher; // If not an alphabet character, return unchanged
}

int main() {
    int a, b;
    char plaintext[1000], ciphertext[1000];

    // Input key values
    printf("Enter the value of 'a' (must be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter the value of 'b': ");
    scanf("%d", &b);

    // Input plaintext
    printf("Enter the plaintext: ");
    scanf(" %[^\n]", plaintext);

    // Encrypt the plaintext
    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = encrypt(plaintext[i], a, b);
    }
    ciphertext[strlen(plaintext)] = '\0';

    // Output the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = decrypt(ciphertext[i], a, b);
    }
    plaintext[strlen(ciphertext)] = '\0';

    // Output the decrypted plaintext
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}

