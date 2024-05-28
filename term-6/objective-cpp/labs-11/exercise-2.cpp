#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <mutex>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> vec(10'000'000);
  std::iota(vec.begin(), vec.end(), 0);
  std::mutex mtx;
  std::vector<int> output;

  auto start_parallel = std::chrono::high_resolution_clock::now();

  std::for_each(std::execution::par, vec.begin(), vec.end(),
                [&output, &mtx](int& elem) {
                  if (elem % 2 == 0) {
                    std::lock_guard<std::mutex> lock(mtx);
                    output.push_back(elem);
                  }
                });

  auto end_parallel = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_parallel =
      end_parallel - start_parallel;

  std::cout << "Czas wykonania (równoległy): " << duration_parallel.count()
            << " sekund" << std::endl;

  std::vector<int> output_seq;
  auto start_sequential = std::chrono::high_resolution_clock::now();

  std::for_each(std::execution::seq, vec.begin(), vec.end(),
                [&output_seq](int& elem) {
                  if (elem % 2 == 0) {
                    output_seq.push_back(elem);
                  }
                });

  auto end_sequential = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_sequential =
      end_sequential - start_sequential;

  std::cout << "Czas wykonania (sekwencyjny): " << duration_sequential.count()
            << " sekund" << std::endl;

  return 0;
}
