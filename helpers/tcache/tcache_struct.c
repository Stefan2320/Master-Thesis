#include <stdio.h>
#include <stdlib.h>


int main(){
	
	void* allocations[64];
	for(int i = 0; i < 64; i++){
		size_t size = 0x20 + i*0x10;
		size -= 0x8; // subtract metadata
		allocations[i] = malloc(size);
		printf("Allocating for size: %ld with index: %d.\n",size,i);
	}
	for(int i = 0; i < 64; i++){
		free(allocations[i]);
	}

	__builtin_trap();


	return 0;
}
