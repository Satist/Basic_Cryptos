//
// Created by johnlamprou on 4/14/21.
//
#include "hy457_crypto.h"

int main(){
    uint8_t *message="HELLO";
    printf("Using HELLO message for default test \n");
    //CEASAR
    printf("Ceasar Test: \n");
    uint8_t *ceasar=ceasar_encrypt(message,2);
    printf("Encrypted Message: %s\n",ceasar);
    printf("Encrypted Message: %s\n",ceasar_decrypt(ceasar,2));

    //AFFINE
    printf("Affine Test : \n");
    uint8_t *affine=message;
    affine=affine_encrypt(affine);
    printf("Encrypted Message: %s\n", affine);
    printf("Decrypted Message: %s\n",affine_decrypt(affine));

    //OTP
    printf("OTP test:\n");
    uint8_t *otp=keygenerator(message);
    printf("Random Key: %s\n",otp);
    uint8_t * en=otp_encrypt(message,otp);
    printf("Encrypted Message: %s\n",en);
    printf("Decrypted Message: %s\n",otp_decrypt(en,otp));

    //PLAYFAIR
    printf("Playfair test using tutorial message and key\n");
    unsigned char* playfair;
    playfair=playfair_encrypt("willattackatdawn", "helloworld");
    printf("Encrypted Message: %s\n", playfair);
    printf("Decrypted Message: %s\n",playfair_decrypt(playfair, "helloworld"));

}