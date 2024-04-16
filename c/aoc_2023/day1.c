#include <stdio.h>
#include <stdlib.h>

// segmentation fault --> killed by SIGSEV

typedef struct {
	int size;
	char* content;
} FILE_BUFFER;

void read_file(char* filepath) {
	FILE* fp;
	fp = fopen(filepath, "r");
	if (fp == NULL) {
		perror(filepath);
		exit(EXIT_FAILURE);
	}

	FILE_BUFFER* buffer = (FILE_BUFFER *) malloc(sizeof(FILE_BUFFER));
	if (buffer == NULL) {
		printf("Could not allocate memory for file buffer\n");
		exit(EXIT_FAILURE);
	}

	char c;
	int index = 0;
	while ((c = getc(fp)) != EOF) {
		// Problem might be here
		// Accessing invalid address
		//buffer->content[index] = (char) c;
	}
	buffer->size = index + 1;

	fclose(fp);

	return buffer;
}

int main(void) {
	char* filepath = "./test";
	FILE_BUFFER* buffer = read_file(filepath);

	//for (int i = 0; i < buffer->size; i++) {
	//	printf("%c", buffer->content[i]);
	//}

	return 0;
}

