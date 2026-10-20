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
    /*size_t l = HEAP_LEFT(i);
    size_t r = HEAP_RIGHT(i);
    size_t largest = i;

    if(l < h->size && h->data[l].priority > h->data[largest].priority)
        largest = l;
    if(r < h->size && h->data[r].priority > h->data[largest]. priority)
        largest = r;

    if(largest != i){
        Process temp = h->data[i];
        h->data[i] = h->data[largest];
        h->data[largest] = temp;
        sift_down(h, largest);
    }*/
    Process temp = h->data[i];

    while(i < h->size / 2){
        size_t l = HEAP_LEFT(i);
        size_t r = HEAP_RIGHT(i);
        size_t  largest = l;

        if(r < h->size && h->data[r].priority > h->data[largest].priority)
            largest = r;

        if(temp.priority >= h->data[largest].priority)
            break;

        h->data[i] = h->data[largest];

        i = largest;
    }

    h->data[i] = temp;

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
    for(size_t i = 0; i < n; i++)
        h->data[i] = src[i];

    h->size = n;
    for(size_t k = (n / 2U); k > 0U; --k){
        sift_down(h, k - 1);
    }
    
  return true;
}

bool heap_push(HeapC* h, Process x) {
  if(h == NULL || h->size == h->capacity) return false;
  /* TODO C3: colocar el elemento al final y subirlo por prioridad.
     No llamar HEAP_PARENT si i == 0. */
    size_t i = h->size;
    h->data[i] = x;

    h->size++;
    while(i > 0){
        size_t p = HEAP_PARENT(i);
        if(h->data[i].priority <= h->data[p].priority) break;

        Process temp = h->data[i];
        h->data[i] = h->data[p];
        h->data[p] = temp;
        
        i = p;
    }
    
  return true;
}

bool heap_pop(HeapC* h, Process* out) {
  if(h == NULL || out == NULL || h->size == 0U) return false;
  /* TODO C4: extraer maximo, sustituir raiz por ultimo y reparar.
     Para heap de 1 elemento no llamar sift_down con heap vacio. */
    *out = h->data[0];
    h->size--;
 
    if(h->size > 0){
        h->data[0] = h->data[h->size];
        sift_down(h, 0);
    }
    return true;
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
