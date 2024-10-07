// Decoder

// Working:
// * Manually paste the encoded hex code of string into the variable ENCODED_ARRAY.
// * Every part of the encoded Hex will be then perform XOR with the mentioned key.
// Valid result will only come if the encoding and decoding key is the same.

#include <stdio.h>
#include <stdlib.h>

#define KEY 0xFA // XOR key

unsigned char* DECODER(unsigned char* encoded_array, size_t size) {
    unsigned char* decoded_array = (unsigned char*)malloc(size * sizeof(unsigned char));
    if (decoded_array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (size_t i = 0; i < size; i++) {
        decoded_array[i] = encoded_array[i] ^ KEY;
    }

    return decoded_array;
}

int main() {

    unsigned char ENCODED_ARRAY[] = { 0x92, 0x9F, 0x96, 0x96, 0x95 };
    size_t size = sizeof(ENCODED_ARRAY) / sizeof(ENCODED_ARRAY[0]);

    unsigned char* decoded_array = DECODER(ENCODED_ARRAY, size);
    
    if (decoded_array == NULL) {
        return EXIT_FAILURE;
    }

    printf("Decoded Array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("0x%02X", decoded_array[i]);
        printf(", ");
    }
    printf("\n");

    free(decoded_array);
    
    return EXIT_SUCCESS;
}