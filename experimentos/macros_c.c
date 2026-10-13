#include <stdio.h>
#define MAX_MACRO(a, b) ((a) > (b) ? (a) : (b))
static inline int max_inline(int a, int b) {
  return a > b ? a : b;
}
int main(void) {
  int a = 9;
  const int b = 3;
  const int macro_result = MAX_MACRO(a++, b); // puede evaluar a++ dos veces
  printf("macro: valor=%d, a=%d\n", macro_result, a);
  a = 9;
  const int inline_result = max_inline(a++, b);
  printf("inline: valor=%d, a=%d\n", inline_result, a);
  puts("Explique la evaluacion repetida de la macro (sin UB en este caso).");
  return 0;
}
