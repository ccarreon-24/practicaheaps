#ifndef HEAP_INDICES_CPP11_HPP
#define HEAP_INDICES_CPP11_HPP
#include <cstddef>
namespace heap11 {
/* inline es redundante: constexpr ya lo implica para funciones. */
inline constexpr std::size_t parent(std::size_t i) {
  return (i - 1U) / 2U; // precondicion: i > 0
}
inline constexpr std::size_t left(std::size_t i) {
  return 2U * i + 1U;
}
inline constexpr std::size_t right(std::size_t i) {
  return 2U * i + 2U;
}
static_assert(parent(9U) == 4U, "padre incorrecto");
static_assert(left(4U) == 9U, "hijo izquierdo incorrecto");
static_assert(right(4U) == 10U, "hijo derecho incorrecto");
}
#endif
