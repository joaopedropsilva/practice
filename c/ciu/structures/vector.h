#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

const int INITIAL_CAPACITY = 16;
const int INITIAL_SIZE = 0;
const int GROWTH_FACTOR = 2;
const float SHRINK_FACTOR = 0.5;

typedef struct {
	int* __addr;
	int __size;
	int __capacity;

} vector_t;

vector_t* vec_create(); 
int vec_size(vector_t *vecptr); 
int vec_capacity(vector_t *vecptr); 
int vec_is_empty(vector_t *vecptr); 
int vec_at(vector_t *vecptr, int index); 
void vec_push(vector_t *vecptr, int item); 
void vec_insert(vector_t *vecptr, int index, int item); 
void vec_prepend(vector_t *vecptr, int item); 
int vec_pop(vector_t *vecptr); 
void vec_delete(vector_t *vecptr, int index); 
void vec_remove(vector_t *vecptr, int item); 

#endif

