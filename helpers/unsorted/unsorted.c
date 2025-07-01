#include <stdio.h>
#include <stdlib.h>


#define TCACHE_MAX 7

int main(){
    size_t sizes[] = {0x80,0x140,0x110};
	
    const int n_sizes = sizeof(sizes) / sizeof(sizes[0]);

    int *chunks[3][TCACHE_MAX + 2];

    for (int i = 0; i < n_sizes; i++) {
        for (int j = 0; j < (TCACHE_MAX + 1); j++) {
            chunks[i][j] = malloc(sizes[i]);
	    malloc(0x10);
        }
    }

    for (int i = 0; i < n_sizes; i++) {
        for (int j = 0; j < (TCACHE_MAX + 1); j++) {
            free(chunks[i][j]);
        }
    }
    puts("free");
	return 0;
}
