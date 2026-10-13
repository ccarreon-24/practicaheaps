#ifndef HEAP_C11_H
#define HEAP_C11_H
#include <stdbool.h>
#include <stddef.h>

typedef struct {
  int pid;
  int priority;
} Process;

typedef struct {
  Process* data;
  size_t size;
  size_t capacity;
} HeapC;

/* Memoria propiedad del heap; capacity fija. */
bool heap_init(HeapC* h, size_t capacity);
void heap_destroy(HeapC* h);
/* Si falla, no altera el heap. */
bool heap_build(HeapC* h, const Process* src, size_t n);
bool heap_push(HeapC* h, Process x);
bool heap_pop(HeapC* h, Process* out);
bool heap_valid(const HeapC* h);
#endif
