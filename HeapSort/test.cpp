#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "HeapSort.h"

#define length 1000000


// check函数
template <typename T>
std::string check(const std::vector<T>& vec) {
    for (int i = 0; i < vec.size()-1; ++i) {
        if (vec[i] > vec[i+1]) {
            return "False";
        }
    }
    return "True";
}

template <typename T>
void measureSortingTime(std::vector<T>& vec, const std::string& description) {
    auto start = std::chrono::high_resolution_clock::now();
    HeapSort<T>::sort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << description<<":"<< diff.count() << " s\n";
    std::cout << "Sorted: " << check(vec) << "\n";
}

template <typename T>
void measure_STL_SortingTime(std::vector<T>& vec, const std::string& description) {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort_heap(vec.begin(), vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << description<<":"<< diff.count() << " s\n";
}

void testSorting() {
  // 随机
    std::vector<int> random_seq(length);
    std::generate(random_seq.begin(), random_seq.end(), std::rand);
    measureSortingTime(random_seq, "Heap sort (random)");

    std::vector<int> vec1 = random_seq; 
    measure_STL_SortingTime(vec1, "Heap std::sort_heap (random)");
    std::cout<<"\n"<<std::endl;

    //顺序
    std::vector<int> ordered_seq(length);
    std::iota(ordered_seq.begin(), ordered_seq.end(), 0);
    measureSortingTime(ordered_seq, "Heap sort (ordered)");

    std::vector<int> vec2 = ordered_seq; 
    measure_STL_SortingTime(vec2, "Heap std::sort_heap (ordered)");
    std::cout<<"\n"<<std::endl;

    // 逆序
    std::vector<int> reverse_seq(length);
    std::iota(reverse_seq.rbegin(), reverse_seq.rend(), 1);
    measureSortingTime(reverse_seq, "Heap sort (reverse)");

    std::vector<int> vec3 = reverse_seq; 
    measure_STL_SortingTime(vec2, "Heap std::sort_heap (reverse)");
    std::cout<<"\n"<<std::endl;

    //重复
    std::vector<int> repetitive_seq(length);
    std::fill(repetitive_seq.begin(), repetitive_seq.end(), 111);
    measureSortingTime(repetitive_seq, "Heap sort (repetitive)");

    std::vector<int> vec4 = repetitive_seq; 
    measure_STL_SortingTime(vec4, "Heap std::sort_heap (repetitive)");
    std::cout<<"\n"<<std::endl;
}

int main() {
    testSorting();
    return 0;
}