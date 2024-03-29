#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 16 // Assuming a block size of 16 bytes (128 bits) for AES encryption

// Function to perform ECB encryption
void ecb_encrypt(const char *plaintext, const char *key) {
    // Implementation of ECB encryption
    printf("ECB Mode Encryption\n");
    // Here, you would perform AES encryption with ECB mode
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    // Dummy output for demonstration
    printf("Ciphertext: ...\n");
}

// Function to perform CBC encryption
void cbc_encrypt(const char *plaintext, const char *key, const char *iv) {
    // Implementation of CBC encryption
    printf("CBC Mode Encryption\n");
    // Here, you would perform AES encryption with CBC mode
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Initialization Vector (IV): %s\n", iv);
    // Dummy output for demonstration
    printf("Ciphertext: ...\n");
}

// Function to simulate error in transmission by flipping a bit in the ciphertext block
void introduce_error(char *ciphertext, int block_num) {
    // For simplicity, let's just flip the first bit of the specified block
    ciphertext[block_num * BLOCK_SIZE] ^= 1;
}

// Function to perform ECB decryption
void ecb_decrypt(const char *ciphertext, const char *key) {
    // Implementation of ECB decryption
    printf("ECB Mode Decryption\n");
    // Here, you would perform AES decryption with ECB mode
    printf("Ciphertext: %s\n", ciphertext);
    printf("Key: %s\n", key);
    // Dummy output for demonstration
    printf("Plaintext: ...\n");
}

// Function to perform CBC decryption
void cbc_decrypt(const char *ciphertext, const char *key, const char *iv) {
    // Implementation of CBC decryption
    printf("CBC Mode Decryption\n");
    // Here, you would perform AES decryption with CBC mode
    printf("Ciphertext: %s\n", ciphertext);
    printf("Key: %s\n", key);
    printf("Initialization Vector (IV): %s\n", iv);
    // Dummy output for demonstration
    printf("Plaintext: ...\n");
}

int main() {
    char plaintext[1000];
    char key[100];
    char iv[100];

    // Get plaintext input from the user
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character if present

    // Get key input from the user
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character if present

    // Get IV input from the user for CBC mode
    printf("Enter initialization vector (IV) for CBC mode: ");
    fgets(iv, sizeof(iv), stdin);
    iv[strcspn(iv, "\n")] = '\0'; // Remove newline character if present

    // Perform ECB encryption
    ecb_encrypt(plaintext, key);

    // Perform CBC encryption
    cbc_encrypt(plaintext, key, iv);

    // Simulate error in transmission (introduce error in first block of ciphertext)
    char ciphertext_ecb[] = "dummy ciphertext for ECB mode";
    char ciphertext_cbc[] = "dummy ciphertext for CBC mode";
    introduce_error(ciphertext_ecb, 0);
    introduce_error(ciphertext_cbc, 0);

    // Perform ECB decryption
    ecb_decrypt(ciphertext_ecb, key);

    // Perform CBC decryption
    cbc_decrypt(ciphertext_cbc, key, iv);

    return 0;
}

