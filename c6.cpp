#include <stdio.h>
#include <stdlib.h>

// Function to find the modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

// Function to decrypt affine cipher
void decryptAffine(char cipher[], int a, int b) {
    int m = 26; // size of the alphabet

    // Finding modular inverse of 'a'
    int a_inv = modInverse(a, m);

    // Decrypting the ciphertext
    for (int i = 0; cipher[i] != '\0'; ++i) {
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            int x = cipher[i] - 'A';
            x = (a_inv * (x - b + m)) % m;
            x += 'A';
            printf("%c", x);
        } else {
            printf("%c", cipher[i]);
        }
    }
    printf("\n");
}

int main() {
    char cipher[] = "YOUR_CIPHERTEXT_HERE"; // Insert the ciphertext here
    int a = 3; // affine transformation coefficient 'a'
    int b = 7; // affine transformation coefficient 'b'

    decryptAffine(cipher, a, b);

    return 0;
}

