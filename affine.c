
#include "hy457_crypto.h"

const int a = 5;
const int b = 8;

uint8_t * affine_encrypt(uint8_t *plaintext){
    uint8_t *cipher=(uint8_t*)malloc(sizeof(uint8_t)*strlen(plaintext));
    for (int i = 0; i < strlen(plaintext); i++)
    {
            cipher[i] =  (char) ((((a * (plaintext[i]-'A') ) + b) % 26) + 'A');

    }
    return cipher;
}

uint8_t * affine_decrypt(uint8_t *ciphertext) {
    uint8_t *plaintext = (uint8_t *) malloc(sizeof(uint8_t) * strlen(ciphertext));
    int a_inv = 0;
    int flag = 0;

    for (int i = 0; i < 26; i++) {
        flag = (a * i) % 26;
        if (flag == 1) {
            a_inv = i;
        }
    }
    for (int i = 0; i < strlen(ciphertext); i++) {
            plaintext[i] = (char) (((a_inv * ((ciphertext[i] + 'A' - b)) % 26)) + 'A');
    }

    return plaintext;
}

