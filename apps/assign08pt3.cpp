#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <algorithm>

void selection_sort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

void quicksort(std::vector<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }
    int pivot = arr[rand() % arr.size()];
    std::vector<int> left, right;
    for (int x : arr) {
        if (x < pivot) {
            left.push_back(x);
        } else if (x > pivot) {
            right.push_back(x);
        }
    }
    quicksort(left);
    quicksort(right);
    arr.clear();
    std::copy(left.begin(), left.end(), std::back_inserter(arr));
    arr.push_back(pivot);
    std::copy(right.begin(), right.end(), std::back_inserter(arr));
}

void heapsort(std::vector<int>& arr) {
    std::make_heap(arr.begin(), arr.end());
    for (int i = arr.size() - 1; i > 0; --i) {
        std::swap(arr[i], arr[0]);
        std::pop_heap(arr.begin(), arr.begin() + i);
    }
}

int main() {
    std::vector<int> arr(10000);
    std::generate(arr.begin(), arr.end(), rand);

    std::cout << "Testing selection sort..." << std::endl;
    auto start = std::chrono::steady_clock::now();
    selection_sort(arr);
    auto end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    std::generate(arr.begin(), arr.end(), rand);

    std::cout << "Testing quicksort..." << std::endl;
    start = std::chrono::steady_clock::now();
    quicksort(arr);
    end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    std::generate(arr.begin(), arr.end(), rand);

    std::cout << "Testing heapsort..." << std::endl;
start = std::chrono::steady_clock::now();
heapsort(arr);
end = std::chrono::steady_clock::now();
std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

return 0;
}