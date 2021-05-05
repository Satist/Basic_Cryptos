
#include <ctype.h>
#include "hy457_crypto.h"


uint8_t* ceasar_encrypt(uint8_t *plaintext, ushort N){
    uint8_t *encrypted=(uint8_t*)malloc(strlen(plaintext)*sizeof(uint8_t));
    uint8_t tmp;
    for(int i=0;i<strlen(plaintext);i++) {
        tmp = (toupper(plaintext[i]) - 'A' + N) % 26 + 'A';
        strncat(encrypted, &tmp, 1);
    }
    return encrypted;
}

uint8_t *ceasar_decrypt(uint8_t *ciphertext, ushort N) {
    uint8_t *decrypted = (uint8_t *) malloc(strlen(ciphertext) * sizeof(uint8_t));
    uint8_t tmp;
    for (int i = 0; i < strlen(ciphertext); i++) {
        tmp = (ciphertext[i] - 'A' - N + 26) % 26 + 'A';
        strncat(decrypted, &tmp, 1);
    }
    return decrypted;
}
