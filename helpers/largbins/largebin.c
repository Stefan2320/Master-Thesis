#include <stdio.h>
#include <stdlib.h>


int main(){
		
	void *chunks[12];
	for (int i = 0; i < 12; i+=2) {
		//chunks[i] = malloc(0x500 + i*0x5);
		chunks[i] = malloc(0x600 + i*0x5);
		malloc(0x10);
		//chunks[i+1] = malloc(0x500 + i*0x2);
		chunks[i+1] = malloc(0x600 + i*0x2);
		malloc(0x10);
	}

	for (int i = 0; i < 12; i+=2) {
		free(chunks[i]);
		malloc(0x20);
		free(chunks[i+1]);
		malloc(0x20);
	}

	puts("gin");
	return 0;
}
