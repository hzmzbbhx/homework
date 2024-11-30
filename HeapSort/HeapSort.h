#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <algorithm> 

template <typename T>
class HeapSort 
{
public:
    static void sort(std::vector<T>& seq);

private:
    static void heapify(std::vector<T>& seq, int n, int i);
};

template <typename T>
void HeapSort<T>::sort(std::vector<T>& seq) 
{
    int n = seq.size();

    for (int i = n / 2; i > 0; --i) 
    {
        heapify(seq, n, i - 1);
    }
    
    for (int i = n - 1; i > 0; --i) 
    {
        std::swap(seq[0], seq[i]); 
        heapify(seq, i, 0);
    }
}

template <typename T>
void HeapSort<T>::heapify(std::vector<T>& seq, int n, int i) 
{
    int largest = i; 
    int left = 2*i+1; 
    int right = 2*i+2; 

    if (left < n && seq[left] > seq[largest]) 
    {
        largest = left;
    }

    if (right < n && seq[right] > seq[largest]) 
    {
        largest = right;
    }

    if (largest != i) 
    {
        std::swap(seq[i], seq[largest]);
        heapify(seq, n, largest); 
    }

    return;
}

#endif // HEAPSORT_H