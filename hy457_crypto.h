//
// Created by johnlamprou on 4/14/21.
//

#ifndef BASICYPHERS_HY457_CRYPTO_H
#define BASICYPHERS_HY457_CRYPTO_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint8_t*keygenerator(uint8_t *plaintext);
uint8_t* ceasar_encrypt(uint8_t *plaintext, ushort N);
uint8_t* ceasar_decrypt(uint8_t *plaintext, ushort N);
uint8_t * otp_encrypt(uint8_t *plaintext,uint8_t *key);
uint8_t * otp_decrypt(uint8_t *ciphertext, uint8_t *key);
uint8_t * affine_encrypt(uint8_t *plaintext);
uint8_t * affine_decrypt(uint8_t *ciphertext);
unsigned char* playfair_encrypt(unsigned char *plaintext, unsigned char** key);
unsigned char* playfair_decrypt(unsigned char *ciphertext, unsigned char** key) ;

#endif //BASICYPHERS_HY457_CRYPTO_H
