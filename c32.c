#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/dsa.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>

// Function to generate a DSA key pair
DSA *generateDSAKey() {
    return DSA_generate_parameters(1024, NULL, 0, NULL, NULL, NULL, NULL);
}

// Function to generate an RSA key pair
RSA *generateRSAKey() {
    return RSA_generate_key(1024, RSA_F4, NULL, NULL);
}

// Function to sign a message using DSA
void signDSA(DSA *dsa, const unsigned char *message, size_t message_len, unsigned char *signature) {
    unsigned int sig_len;
    DSA_sign(0, message, message_len, signature, &sig_len, dsa);
}

// Function to sign a message using RSA
void signRSA(RSA *rsa, const unsigned char *message, size_t message_len, unsigned char *signature) {
    unsigned int sig_len;
    RSA_sign(NID_sha256, message, message_len, signature, &sig_len, rsa);
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Generate DSA key pair
    DSA *dsa = generateDSAKey();
    if (dsa == NULL) {
        printf("Error generating DSA key pair.\n");
        return 1;
    }

    // Generate RSA key pair
    RSA *rsa = generateRSAKey();
    if (rsa == NULL) {
        printf("Error generating RSA key pair.\n");
        return 1;
    }

    // Message to be signed
    unsigned char message[] = "Hello, world!";
    size_t message_len = strlen((const char *)message);

    // Sign the message using DSA
    unsigned char dsa_signature[DSA_size(dsa)];
    signDSA(dsa, message, message_len, dsa_signature);

    // Sign the message using RSA
    unsigned char rsa_signature[1024]; // Sufficient size for RSA signature
    signRSA(rsa, message, message_len, rsa_signature);

    // Print the DSA signature
    printf("DSA Signature: ");
    for (int i = 0; i < DSA_size(dsa); i++) {
        printf("%02x", dsa_signature[i]);
    }
    printf("\n");

    // Print the RSA signature
    printf("RSA Signature: ");
    for (int i = 0; i < RSA_size(rsa); i++) {
        printf("%02x", rsa_signature[i]);
    }
    printf("\n");

    // Free memory
    DSA_free(dsa);
    RSA_free(rsa);

    return 0;
}

