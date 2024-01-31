#include <stdio.h>
#include <stdlib.h>

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

int main(void) {
	int capacity = 16;
	int size = 0;
	int char_typed;

	int* arr = (int*) malloc(capacity * sizeof(int));

	if (arr == NULL) {
		printf("Could not allocate memory\n");

		return 1;
	}

	// break this loop reading everything as chars
	// after that try casting the input to int
	// compare with 'q' char to quit
	while (1) {
		if (size == capacity) {
			capacity *= 2;
			arr = (int*) realloc(arr, capacity * sizeof(int));
		}

		int values_read = scanf(" %d", &char_typed);
		printf("read: %d\n", values_read);

		if (values_read == 1) {
			arr[size] = char_typed;
			size++;
		}
	}

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

