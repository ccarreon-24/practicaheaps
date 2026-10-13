#include "heap.h"
#include "indices.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Max-heap: se compara priority; en un empate cualquiera es valido. */
static void sift_down(HeapC* h, size_t i) {
  /* TODO C1: reparar hacia abajo, en O(log n) tiempo y O(1) espacio.
     Precondicion: los subarboles hijos de i ya son heaps.
     Comprobar existencia ANTES de calcular/acceder a los hijos. */
  (void)h;
  (void)i;
}

bool heap_init(HeapC* h, size_t capacity) {
  if(h == NULL) return false;
  h->data = NULL;
  h->size = 0U;
  h->capacity = 0U;
  if(capacity > SIZE_MAX / sizeof(Process)) return false;
  if(capacity != 0U) {
    h->data = malloc(capacity * sizeof(Process));
    if(h->data == NULL) return false;
  }
  h->capacity = capacity;
  return true;
}

void heap_destroy(HeapC* h) {
  if(h == NULL) return;
  free(h->data);
  h->data = NULL;
  h->size = 0U;
  h->capacity = 0U;
}

bool heap_build(HeapC* h, const Process* src, size_t n) {
  if(h == NULL || n > h->capacity || (n != 0U && src == NULL))
    return false;
  /* TODO C2: copiar src, actualizar size y construir bottom-up.
     Utilizar: for(size_t k = n / 2U; k > 0U; --k) ...
     El codigo tambien debe aceptar n == 0. */
  (void)src;
  (void)sift_down; /* evita una advertencia antes de completar los TODO */
  return true;
}

bool heap_push(HeapC* h, Process x) {
  if(h == NULL || h->size == h->capacity) return false;
  /* TODO C3: colocar el elemento al final y subirlo por prioridad.
     No llamar HEAP_PARENT si i == 0. */
  (void)x;
  return false;
}

bool heap_pop(HeapC* h, Process* out) {
  if(h == NULL || out == NULL || h->size == 0U) return false;
  /* TODO C4: extraer maximo, sustituir raiz por ultimo y reparar.
     Para heap de 1 elemento no llamar sift_down con heap vacio. */
  return false;
}

bool heap_valid(const HeapC* h) {
  if(h == NULL || h->size > h->capacity ||
     (h->capacity != 0U && h->data == NULL)) return false;
  for(size_t i = 1U; i < h->size; ++i) {
    if(h->data[HEAP_PARENT(i)].priority < h->data[i].priority)
      return false;
  }
  return true;
}
