#include <iostream>
#include <vector>
#include <chrono>
#include <random>

void selection_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}


std::vector<int> generate_random_ints(int size) {
    std::vector<int> nums(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100000);
    for (int i = 0; i < size; i++) {
        nums[i] = dis(gen);
    }
    return nums;
}


int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

std::vector<int>& generateRandomVector(int size) {
    static std::vector<int> vec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 100000);
    for (int i = 0; i < size; i++) {
        vec[i] = distrib(gen);
    }
    return vec;
}

int main() {
    int vector_sizes[] = {5, 10, 20, 50, 100, 1000, 10000, 50000};
    int num_sizes = sizeof(vector_sizes) / sizeof(vector_sizes[0]);

    for (int i = 0; i < num_sizes; ++i) {
    int size = vector_sizes[i];
    std::vector<int> arr = generate_random_ints(size);
    
    // Selection Sort
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    selection_sort(arr);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto selection_sort_duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    
    // Quick Sort
    t1 = std::chrono::high_resolution_clock::now();
    quicksort(arr, 0, size - 1);
    t2 = std::chrono::high_resolution_clock::now();
    auto quick_sort_duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    std::cout << "Vector size: " << size << "\n";
    std::cout << "Selection Sort Time: " << selection_sort_duration << " microseconds\n";
    std::cout << "Quick Sort Time: " << quick_sort_duration << " microseconds\n\n";
}
    return 0;
}
