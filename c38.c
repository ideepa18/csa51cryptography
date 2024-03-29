#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

// Function to find modular inverse of a number
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Function to find determinant of a 2x2 matrix
int determinant(int matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// Function to find the modulo of a number (handles negative numbers)
int modulo(int a, int m) {
    int mod = a % m;
    return mod < 0 ? mod + m : mod;
}

// Function to calculate the cofactor of a matrix
void cofactor(int matrix[2][2], int temp[2][2]) {
    temp[0][0] = matrix[1][1];
    temp[0][1] = -matrix[0][1];
    temp[1][0] = -matrix[1][0];
    temp[1][1] = matrix[0][0];
}

// Function to transpose a matrix
void transpose(int matrix[2][2], int temp[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            temp[i][j] = matrix[j][i];
        }
    }
}

// Function to find adjoint of a matrix
void adjoint(int matrix[2][2], int adj[2][2]) {
    int temp[2][2];
    cofactor(matrix, temp);
    transpose(temp, adj);
}

// Function to find the inverse of a matrix
int inverse(int matrix[2][2], int inv[2][2]) {
    int det = determinant(matrix);
    if (det == 0) {
        return 0; // Matrix is not invertible
    }

    int adj[2][2];
    adjoint(matrix, adj);
    int inv_det = mod_inverse(det, ALPHABET_SIZE);
    if (inv_det == -1) {
        return 0; // Modular inverse doesn't exist
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            inv[i][j] = modulo(adj[i][j] * inv_det, ALPHABET_SIZE);
        }
    }
    return 1;
}

int main() {
    // Input plaintext-ciphertext pairs from the user
    char chosen_plaintexts[10][3], chosen_ciphertexts[10][3];
    int num_pairs;

    printf("Enter the number of plaintext-ciphertext pairs (max 10): ");
    scanf("%d", &num_pairs);
    getchar(); // Consume newline character

    if (num_pairs > 10 || num_pairs <= 0) {
        printf("Invalid number of pairs. Exiting.\n");
        return 1;
    }

    printf("Enter the plaintext-ciphertext pairs (format: plaintext ciphertext):\n");
    for (int i = 0; i < num_pairs; i++) {
        printf("Pair %d: ", i + 1);
        scanf("%s %s", chosen_plaintexts[i], chosen_ciphertexts[i]);
        getchar(); // Consume newline character
    }

    // Calculate the key matrix using chosen plaintext-ciphertext pairs
    int plain_matrix[2][2] = {{0}};
    int cipher_matrix[2][2] = {{0}};
    int inv_plain_matrix[2][2] = {{0}};
    int key_matrix[2][2] = {{0}};

    for (int i = 0; i < num_pairs; i++) {
        plain_matrix[0][0] = chosen_plaintexts[i][0] - 'a';
        plain_matrix[1][0] = chosen_plaintexts[i][1] - 'a';
        cipher_matrix[0][0] = chosen_ciphertexts[i][0] - 'a';
        cipher_matrix[1][0] = chosen_ciphertexts[i][1] - 'a';

        if (!inverse(plain_matrix, inv_plain_matrix)) {
            printf("Error: Plain matrix is not invertible\n");
            return 1;
        }

        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                key_matrix[j][k] += inv_plain_matrix[j][k] * cipher_matrix[k][0];
                key_matrix[j][k] %= ALPHABET_SIZE; // Modulo operation to keep result within alphabet size
            }
        }
    }

    printf("Recovered Key Matrix:\n");
    printf("%d %d\n", key_matrix[0][0], key_matrix[0][1]);
    printf("%d %d\n", key_matrix[1][0], key_matrix[1][1]);

    return 0;
}



