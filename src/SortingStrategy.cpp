#include "../include/SortingStrategy.h"
#include <algorithm>
#include <stdexcept>

void BubbleSortStrategy::sort(std::vector<int>& data) {
    bool swapped;
    for (size_t i = 0; i < data.size(); ++i) {
        swapped = false;
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            if (data[j] > data[j+1]) {
                std::swap(data[j], data[j+1]);
                swapped = true;
            }
        }
        if (swapped = false) break;
    }
}



void QuickSortStrategy::sort(std::vector<int>& data) {
    QuickSort(data, 0, data.size() - 1);
}

void QuickSortStrategy::QuickSort(std::vector<int>& data, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(data, low, high);
        QuickSort(data, low, pivotIndex - 1);
        QuickSort(data, pivotIndex + 1, high);
    }
}

int QuickSortStrategy::partition(std::vector<int>& data, int low, int high) {
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (data[j] < pivot) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i+1], data[high]);
    return i+1;
}



void StdSortStrategy::sort(std::vector<int>& data) {
    std::sort(data.begin(), data.end());
}



void InsertionSortStrategy::sort(std::vector<int>& data) {
    for (size_t i = 1; i < data.size(); ++i) {
        int j = static_cast<int>(i) - 1;
        int key = data[i];
        while (j >= 0 && data[j] > key) {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
}



Sorter::Sorter(std::unique_ptr<SortingStrategy> strategy) : strategy_(std::move(strategy)) {}

void Sorter::SortData(std::vector<int>& data) {
    if (strategy_) {
        strategy_->sort(data);
    } else {
        throw std::runtime_error("Sorting strategy is not set");
    }
}

void Sorter::setStrategy(std::unique_ptr<SortingStrategy> newStrategy) {
    strategy_ = std::move(newStrategy);
}
