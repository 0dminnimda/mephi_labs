#include "vector.h"

#include <stdlib.h>

typedef struct VectorNode {
    vector_item_t *data;
    size_t capacity;
    size_t length;
} VectorNode;

vector_item_t get_item(Vector vec, size_t index) { return vec->data[index]; }

void set_item(Vector vec, size_t index, vector_item_t value) {
    vec->data[index] = value;
}

size_t get_capacity(Vector vec) { return vec->capacity; }

size_t get_length(Vector vec) { return vec->length; }

void reset_length(Vector vec) { vec->length = 0; }

int create(Vector *vec, size_t capacity) {
    *vec = malloc(sizeof(VectorNode));
    if (*vec == NULL) return -1;

    vector_item_t *data = malloc(capacity * sizeof(vector_item_t));
    if (data == NULL) return -1;

    (*vec)->data = data;
    (*vec)->capacity = capacity;
    (*vec)->length = 0;

    return 0;
}

void destroy(Vector vec) {
    free(vec->data);
    free(vec);
}

int reserve(Vector vec, size_t capacity) {
    if (capacity <= vec->capacity) return 0;

    vector_item_t *data = realloc(vec->data, capacity * sizeof(vector_item_t));
    if (data == NULL) return -1;

    vec->data = data;
    vec->capacity = capacity;

    return 0;
}

int push_back(Vector vec, vector_item_t value) {
    if (vec->capacity == vec->length)
        if (reserve(vec, vec->capacity * 2 + 1)) return -1;

    set_item(vec, vec->length, value);
    vec->length++;

    return 0;
}