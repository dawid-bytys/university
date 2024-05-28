#include <iostream>
#include <cstdlib>

struct No_checking_policy {
  void check_push(size_t, size_t) const {}
  void check_pop(size_t) const {}
  void check_top(size_t) const {}
};

struct Abort_on_error_policy {
  void check_push(size_t current_size, size_t max_size) const {
    if (current_size >= max_size) {
      std::cerr << "Stack overflow error\n";
      std::abort();
    }
  }

  void check_pop(size_t current_size) const {
    if (current_size == 0) {
      std::cerr << "Stack underflow error\n";
      std::abort();
    }
  }
  
  void check_top(size_t current_size) const {
    if (current_size == 0) {
      std::cerr << "Stack empty error on accessing top\n";
      std::abort();
    }
  }
};

// Definicja szablonu alokatora ze statyczną tablicą
template<typename T, size_t N>
struct Static_table_allocator {
    typedef T rep_type[N];

    void init(rep_type &array, size_t) { std::fill(array, array + N, T{}); }
    void expand_if_needed(rep_type &, size_t) {} // Static allocation does not expand
    void shrink_if_needed(rep_type &, size_t) {} // nor shrink
    void deallocate(rep_type &) {} // No dynamic memory to free
    static size_t size() { return N; }
};

template<
    typename T = int,
    size_t N = 100,
    typename Checking_policy = No_checking_policy,
    template<typename U, size_t M> class Allocator_policy = Static_table_allocator
>
class Stack {
private:
    typename Allocator_policy<T, N>::rep_type _rep; // Using associated type from the allocator
    size_t _top;
    Checking_policy _policy;
    Allocator_policy<T, N> _allocator; // Instance of the allocator policy

public:
    Stack() : _top(0) {
        _allocator.init(_rep, N);
    }

    void push(const T& value) {
        _policy.check_push(_top, N);
        _allocator.expand_if_needed(_rep, _top);
        _rep[_top++] = value;
    }

    void pop() {
        _policy.check_pop(_top);
        _top--;
        _allocator.shrink_if_needed(_rep, _top);
    }

    T& top() {
        _policy.check_top(_top);
        return _rep[_top - 1];
    }

    const T& top() const {
        _policy.check_top(_top);
        return _rep[_top - 1];
    }

    bool empty() const {
        return _top == 0;
    }

    size_t size() const {
        return _top;
    }
};


template<typename T, size_t InitialSize = 0>
class Dynamic_table_allocator {
public:
    using rep_type = T*;
    size_t _capacity;

    Dynamic_table_allocator() : _capacity(InitialSize) {}

    void init(rep_type &array, size_t) {
        array = new T[_capacity];
    }

    void expand_if_needed(rep_type &array, size_t current_size) {
        if (current_size >= _capacity) {
            size_t new_capacity = _capacity * 2 + ( _capacity == 0 ? 1 : 0 );  // double size or initialize to 1
            T* new_array = new T[new_capacity];
            std::copy(array, array + _capacity, new_array);
            delete[] array;
            array = new_array;
            _capacity = new_capacity;
        }
    }

    void shrink_if_needed(rep_type &array, size_t current_size) {
        if (current_size < _capacity / 2 && _capacity > InitialSize) {
            size_t new_capacity = _capacity / 2;
            T* new_array = new T[new_capacity];
            std::copy(array, array + new_capacity, new_array);
            delete[] array;
            array = new_array;
            _capacity = new_capacity;
        }
    }

    void deallocate(rep_type &array) {
        delete[] array;
    }

    size_t size() const {
        return _capacity;
    }
};


int main() {
  Stack<int, 10, No_checking_policy> stack1;
  stack1.push(1);
  stack1.push(2);
  std::cout << "Top element of stack1: " << stack1.top() << std::endl;
  
  Stack<int, 2, Abort_on_error_policy> stack2;
  stack2.push(1);
  stack2.push(2);
  stack2.push(3);

  return 0;
}
