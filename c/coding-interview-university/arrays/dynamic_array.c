#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int easiest_example_of_dynamic_array(void) {
	int* arr;
	int size;

	printf("What is the size of the array? ");
	scanf("%d", &size);
	
	arr = (int*) malloc(size * sizeof(int));

	if (arr == NULL) {
		printf("Could not allocate memory\n");

		return 1;
	}

	printf("Fill the wanted values of the array: ");
	for (int i = 0; i < size; i++) {
		scanf("%d", (i + arr));
	}

	printf("Array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", *(i + arr));
	}
	printf("\n");

	return 0;
}

int auto_resizable_dynamic_array(void) {
	int capacity = 16;
	int size = 0;
	char char_typed;

	int* arr = (int*) malloc(capacity * sizeof(int));

	if (arr == NULL) {
		printf("Could not allocate memory\n");

		return 1;
	}

	while (1) {
		if (size == capacity) {
			capacity *= 2;
			arr = (int*) realloc(arr, capacity * sizeof(int));
		}

		if (arr == NULL) {
			printf("Could not allocate memory\n");

			return 1;
		}

		scanf(" %c", &char_typed);
		
		if (isalpha(char_typed))
			break;

		arr[size] = atoi(&char_typed);
		size++;
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
