// Encoder:

// Working:
// * Manually paste the original hex code of string into the variable INPUT_ARRAY.
// * Every part of the Original Hex will be then perform XOR with the mentioned key.

// Uses:
// * We can't just store normal hex values inside a .exe file, because the original string representaion is still visible while reverse engineering.

#include <stdio.h>
#include <stdlib.h>

#define KEY 0xFA // XOR key

unsigned char* ENCODER(unsigned char* input_array, size_t size) {
    unsigned char* output_array = (unsigned char*)malloc(size * sizeof(unsigned char));
    if (output_array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (size_t i = 0; i < size; i++) {
        output_array[i] = input_array[i] ^ KEY;
    }

    return output_array;
}

int main() {
    // Input array
    unsigned char INPUT_ARRAY[] = { 0x2D, 0x5B, 0x2D, 0x2D, 0x2D, 0x3E, 0x2B, 0x3C, 0x5D };

    size_t size = sizeof(INPUT_ARRAY) / sizeof(INPUT_ARRAY[0]);

    unsigned char* encoded_array = ENCODER(INPUT_ARRAY, size);
    
    if (encoded_array == NULL) {
        return EXIT_FAILURE;
    }

    printf("Encoded Array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("0x%02X", encoded_array[i]);
        printf(", ");
    }
    printf("\n");

    free(encoded_array);
    
    return EXIT_SUCCESS;
}