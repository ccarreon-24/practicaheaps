#include "heap.hpp"
#include "indices.hpp"
#include <utility>
namespace heap11 {
Heap::Heap(std::size_t capacity) : capacity_(capacity) {
  data_.reserve(capacity_); // puede lanzar std::bad_alloc
}

void Heap::sift_down(std::size_t i) {
  /* TODO CPP1: portar el sift_down de C utilizando parent/left/right
     cuando corresponda, std::swap y std::vector.
     Mejor alternativa: implementar sin swaps, usando un temporal. */
    /*size_t l = left(i);
    size_t r = right(i);
    size_t largest = i;

    if(l < data_.size() && data_[l].priority > data_[largest].priority)
        largest = l;
    if(r < data_.size() && data_[r].priority > data_[largest].priority)
        largest = r;

    if(largest != i){
        Process temp = data_[i];
        data_[i] = data_[largest];
        data_[largest] = temp;
        sift_down(largest);
    }*/

    Process temp = data_[i];

    while(i < data_.size() / 2){
        size_t l = left(i);
        size_t r = right(i);
        size_t largest = l;

        if(r < data_.size() && data_[r].priority > data_[largest].priority)
            largest = r;

        if(temp.priority >= data_[largest].priority)
            break;

        data_[i] = data_[largest];

        i = largest;
    }

    data_[i] = temp;

}

bool Heap::build(const std::vector<Process>& input) {
  if(input.size() > capacity_) return false;
  data_ = input;
  for(std::size_t k = data_.size() / 2U; k > 0U; --k)
    sift_down(k - 1U);
  return true;
}

bool Heap::push(Process x) {
  if(data_.size() == capacity_) return false;
  data_.push_back(x);
  std::size_t i = data_.size() - 1U;
  while(i > 0U && data_[parent(i)].priority < data_[i].priority) {
    std::swap(data_[i], data_[parent(i)]);
    i = parent(i);
  }
  return true;
}

bool Heap::pop(Process& out) {
  if(data_.empty()) return false;
  out = data_.front();
  data_.front() = data_.back();
  data_.pop_back();
  if(!data_.empty()) sift_down(0U);
  return true;
}

bool Heap::valid() const {
  for(std::size_t i = 1U; i < data_.size(); ++i) {
    if(data_[parent(i)].priority < data_[i].priority) return false;
  }
  return true;
}
}
