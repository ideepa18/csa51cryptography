#include <stdio.h>

// Function to decrypt a simple substitution cipher
void decryptSubstitution(char cipher[]) {
    // Define the substitution key
    char substitutionKey[26] = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L', 'C', 'U', 'M', 'W', 'F', 'G', 'Y', 'P', 'B', 'V', 'K', 'J', 'X', 'Q', 'Z'};

    // Decrypting the ciphertext
    for (int i = 0; cipher[i] != '\0'; ++i) {
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            printf("%c", substitutionKey[cipher[i] - 'A']);
        } else {
            printf("%c", cipher[i]);
        }
    }
    printf("\n");
}

int main() {
    char cipher[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?";
    
    decryptSubstitution(cipher);

    return 0;
}

