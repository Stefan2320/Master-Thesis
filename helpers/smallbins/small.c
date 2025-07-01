#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    const int count = 10;

    size_t chunk_size1 = 0x100;
    size_t chunk_size2 = 0x140;

    void *chunks1[count];
    void *chunks2[count];

    for (int i = 0; i < count; i++) {
        chunks1[i] = malloc(chunk_size1);
    	malloc(0x20);
    }

    malloc(0x20);
    for (int i = 0; i < count; i++) {
        chunks2[i] = malloc(chunk_size2);
    	malloc(0x20);
    }


    for (int i = 0; i < count; i++) {
        free(chunks1[i]);
    }
    for (int i = 0; i < count; i++) {
        free(chunks2[i]);
    }

    malloc(0x440); // trigger consolidation/ moving to smallbin


    puts("Freed");
    return 0;
}

