#include "hy457_crypto.h"


int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

unsigned char** playfair_keymatrix(unsigned char *key) {
    int i, j, k, *hashmap;
    unsigned char **keyT = (unsigned char **) malloc(sizeof(unsigned char *)*25);
    for (int l = 0; l < 5; ++l) {
        keyT[l]=(unsigned char*)malloc(sizeof(unsigned char));
    }
    hashmap = (int *) calloc(26, sizeof(int));
    for (i = 0; i < strlen(key); i++) {
        if (key[i] != 'j')
            hashmap[key[i] - 97] = 2;
    }
    hashmap['j' - 97] = 1;
    i = 0;
    j = 0;
    for (k = 0; k < strlen(key); k++) {
        if (hashmap[key[k] - 97] == 2) {
            hashmap[key[k] - 97] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }

    for (k = 0; k < 26; k++) {
        if (hashmap[k] == 0) {
            keyT[i][j] = (char) (k + 97);
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
    return keyT;
}

unsigned char *prepare_plaintxt(unsigned char* plaintext){
    size_t len=strlen(plaintext);
    unsigned char* fixedtext=strdup(plaintext);
    if (len%3==0){
        fixedtext[len-1]='x';
    }
    for (int i = 0; i < len; i=i+2) {
            if (fixedtext[i]==fixedtext[i+1])
                fixedtext[i+1]='x';
    }
    return fixedtext;
}

int* search(unsigned char **keyT,unsigned char a,unsigned char b){
    int* arr=malloc(sizeof(int)*4);
    int i, j;
    if (a == 'j')
        a = 'i';
    else if (b == 'j')
        b = 'i';
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (keyT[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyT[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
    return arr;
}

unsigned char* playfair_encrypt(unsigned char *plaintext, unsigned char** key){
    int i, *a;
    unsigned char** keyT=playfair_keymatrix("helloworld");
    plaintext=prepare_plaintxt(plaintext);
    for (i = 0; i < strlen(plaintext); i += 2) {

        a=search(keyT, plaintext[i], plaintext[i + 1]);

        if (a[0] == a[2]) {
            plaintext[i] = keyT[a[0]][mod((a[1] + 1),5)];
            plaintext[i + 1] = keyT[a[0]][mod((a[3] + 1),5)];
        }
        else if (a[1] == a[3]) {
            plaintext[i] = keyT[mod((a[0] + 1),5)][a[1]];
            plaintext[i + 1] = keyT[mod((a[2] + 1),5)][a[1]];
        }
        else {
            plaintext[i] = keyT[a[0]][a[3]];
            plaintext[i + 1] = keyT[a[2]][a[1]];
        }
    }
    return plaintext;
}

unsigned char* playfair_decrypt(unsigned char *ciphertext, unsigned char** key) {
    int i, *a;
    unsigned char **keyT = playfair_keymatrix(key);
    for (i = 0; i < strlen(ciphertext); i += 2) {
        a = search(keyT, ciphertext[i], ciphertext[i + 1]);
        if (a[0] == a[2]) {
            ciphertext[i] = keyT[a[0]][mod((a[1] - 1) , 5)];
            ciphertext[i + 1] = keyT[a[0]][mod((a[3] - 1) , 5)];
        } else if (a[1] == a[3]) {
            ciphertext[i] = keyT[mod((a[0] - 1) , 5)][a[1]];
            ciphertext[i + 1] = keyT[mod((a[2] - 1) , 5)][a[1]];
        } else {
            ciphertext[i] = keyT[a[0]][a[3]];
            ciphertext[i + 1] = keyT[a[2]][a[1]];
        }
    }
    return ciphertext;
}

