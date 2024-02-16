#include <stdio.h>
#include <stdlib.h>

#define __shift_left(start_index, vec) \
	for (int i = start_index; i < vec.__size - 1; i++) \
		vec.__addr[i] = vec.__addr[i + 1]
#define delete(index, vec) \
	__shift_left(index, vec); \
	__decrement_size(vec); \
	if (__is_size_a_quarter(vec)) \
		__resize_by(0.5, vec)
#define remove(item, vec) \
	printf(">> item to remove: %d\n", item); \
	int i = 0; \
	while (1) { \
		if (i == vec.__size - 1) { \
			break; \
		} \
		if (item == vec.__addr[i]) { \
			printf(">> item found %d\n", vec.__addr[i]); \
			printf(">> index %d\n", i); \
			__shift_left(i, vec); \
			__decrement_size(vec); \
		} \
		i++; \
	}

int __is_full(vector_t *vecptr) { return (vecptr->__size == vecptr->__capacity); }

int __is_size_a_quarter(vector_t *vecptr) { return (vecptr->__size == (vecptr->__capacity * 0.25)); }

int __resize_by(vector_t *vecptr, float factor) {
	vecptr->__capacity *= factor;
	vecptr->__addr = (int *) realloc(vecptr->__addr, sizeof(int) * vecptr->__capacity);

	if (vecptr->__addr == NULL)
		return 0;

	return 1;
}

int __resize_based_on(vector_t *vecptr, int (*resize_condition)(), float factor) {
	int did_resize = 0;
	int is_resize_cond_fulfilled = resize_condition(vecptr);

	if (is_resize_cond_fulfilled)
		did_resize = __resize_by(vecptr, factor);

	if (is_resize_cond_fulfilled && !did_resize) {
		// DEBUG
		printf("Could not allocate memory for the vector\n");

		return 0;
	}

	return 1;
}

// Does not evaluate if vector has space,
// it assumes vecptr->__addr[size(vecptr)]
// is a valid position
void __shift_right(vector_t *vecptr, int start_index) {
	for (int i = vecptr->__size - 1; i >= start_index; i--)
		vecptr->__addr[i + 1] = vecptr->__addr[i];
}

vector_t *vec_create() {
	vector_t *v = (vector_t *) malloc(sizeof(vector_t));

	v->__addr = (int *) malloc(sizeof(int) * INITIAL_CAPACITY);

	if (v->__addr == NULL) {
		printf("Could not allocate memory for vector\n");
		printf("Exiting...\n");

		exit(1);
	}

	v->__size = INITIAL_SIZE;
	v->__capacity = INITIAL_CAPACITY;

	return v;
}

int vec_size(vector_t *vecptr) { return vecptr->__size; }

int vec_capacity(vector_t *vecptr) { return vecptr->__capacity; }

int vec_is_empty(vector_t *vecptr) { return (vecptr->__size == 0); }

int vec_at(vector_t *vecptr, int index) { return ((index >= vecptr->__size) ? -1 : vecptr->__addr[index]); }

void vec_push(vector_t *vecptr, int item) {
	int __resize_result = __resize_based_on(vecptr, __is_full, GROWTH_FACTOR);
	if(!__resize_result)
		exit(1);

	vecptr->__addr[vecptr->__size] = item;
	vecptr->__size++;
}; 

void vec_insert(vector_t *vecptr, int index, int item) {
	int __resize_result = __resize_based_on(vecptr, __is_full, GROWTH_FACTOR);
	if(!__resize_result)
		exit(1);

	__shift_right(vecptr, index);
	vecptr->__addr[index] = item;
	vecptr->__size++;
}

void vec_prepend(vector_t *vecptr, int item) { vec_insert(vecptr, 0, item); }

int vec_pop(vector_t *vecptr) {
	int last_item = vecptr->__addr[vecptr->__size - 1];

	vecptr->__addr[vecptr->__size - 1] = 0;
	vecptr->__size--;

	int __resize_result = __resize_based_on(vecptr, __is_size_a_quarter, SHRINK_FACTOR);
	if (!__resize_result)
		exit(1);

	return last_item;
}

