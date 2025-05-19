#ifndef SORTINGSTRATEGY_H
#define SORTINGSTRATEGY_H

#include <vector>
#include <memory>

class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
    virtual ~SortingStrategy() = default;
};



class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override;
};

class QuickSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override;
private:
    void QuickSort(std::vector<int>& data, int low, int high);
    int partition(std::vector<int>& data, int low, int high);
};

class StdSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override;
};

class InsertionSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override;
};



class Sorter {
public:
    explicit Sorter(std::unique_ptr<SortingStrategy> strategy);
    void SortData(std::vector<int>& data);
    void setStrategy(std::unique_ptr<SortingStrategy> newStrategy);
private:
    std::unique_ptr<SortingStrategy> strategy_;
};

#endif 