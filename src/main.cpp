#include <iostream>
#include <vector>
#include "../include/SortingStrategy.h"

void printData(std::vector<int>& data) {
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::vector<int> data = {54, 65, 3, 98, 6, 12, 97, 245, 34, 43};

    std::cout << "Initial data: ";
    printData(data);


    Sorter sorter(std::make_unique<BubbleSortStrategy>());

    sorter.SortData(data);
    std::cout << "Data after BubbleSortStrategy: ";
    printData(data);


    data = {54, 65, 3, 98, 6, 12, 97, 245, 34, 43};
    sorter.setStrategy(std::make_unique<QuickSortStrategy>());
    sorter.SortData(data);
    std::cout << "Data after QuickSortStrategy: ";
    printData(data);


    data = {54, 65, 3, 98, 6, 12, 97, 245, 34, 43};
    sorter.setStrategy(std::make_unique<StdSortStrategy>());
    sorter.SortData(data);
    std::cout << "Data after StdSortStrategy: ";
    printData(data);


    data = {54, 65, 3, 98, 6, 12, 97, 245, 34, 43};
    sorter.setStrategy(std::make_unique<InsertionSortStrategy>());
    sorter.SortData(data);
    std::cout << "Data after InsertionSortStrategy: ";
    printData(data);

    return 0;
}