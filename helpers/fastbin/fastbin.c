#include <stdio.h>
#include <stdlib.h>


#define MAX_TCACHE 7

int main(){
	
	size_t size[]={0x50, 0x70};
	int n = sizeof(size)/sizeof(size[0]);
	void *chunks[2][MAX_TCACHE+2];

	for(int i = 0; i < n; i++){
		for(int j=0; j < MAX_TCACHE+2;j++){
			chunks[i][j] = malloc(size[i]);
			malloc(0x20); 
		}
	}

	for(int i = 0; i < n; i++){
		for(int j=0; j < MAX_TCACHE+2;j++){
			free(chunks[i][j]);
		}
	}

	puts("Free.");

	return 0;
}
