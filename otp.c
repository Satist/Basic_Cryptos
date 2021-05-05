#include "hy457_crypto.h"
#include "base64.h"



uint8_t* keygenerator(uint8_t *plaintext){
    uint8_t * storedkey;
    FILE *fp;
    size_t len=strlen(plaintext);
    storedkey=(uint8_t *)malloc(len*sizeof(uint8_t));
    char chlen[len];
    char *command="tr -dc A-Za-z0-9 </dev/urandom | head -c";
    sprintf(chlen,"%zu",len);
    char *finalcommand=(char*) malloc(strlen(chlen) + strlen(command) + 1);
    strcat(finalcommand,command);
    strcat(finalcommand,chlen);
    /* Open the command for reading. */
    fp = popen(finalcommand, "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }
    fscanf(fp,"%s",storedkey);
    /* close */
    pclose(fp);
    return storedkey;
}

uint8_t * otp_encrypt(uint8_t *plaintext,uint8_t *key){
    size_t len=strlen(plaintext);
    uint8_t *encrypted=(uint8_t *)malloc(2*len* sizeof(uint8_t ));
    for (int i = 0; i < len; ++i) {
        encrypted[i]=plaintext[i]^key[i];
    }
    encrypted=base64_encode(encrypted,len,NULL);
    return encrypted;
}

uint8_t * otp_decrypt(uint8_t *ciphertext, uint8_t *key){
    size_t len=strlen(ciphertext);
    uint8_t *decrypted=(uint8_t *)malloc(2*len* sizeof(uint8_t ));
    ciphertext=base64_decode(ciphertext,len,NULL);
    for (int i = 0; i < len; ++i) {
        decrypted[i]=ciphertext[i]^key[i];
    }
    return decrypted;
}


