//
// Created by alanp on 05/02/2019.
//
#pragma once

#include <vector>

template<class Iterator>
Iterator Partition(Iterator begin, Iterator end) {
    auto middle = begin + (end - begin) / 2;
    if(*begin <= *middle && *middle <= *(end - 1)) std::swap(*middle, *(end - 1));
    else if(*middle <= *begin && *begin <= *(end - 1)) std::swap(*begin, *(end - 1));
    auto pivot = *(end - 1);
    auto write_pos = begin;
    for (auto it = begin; it < end - 1; it++) {
        if (*it < pivot) std::swap(*(write_pos++), *it);
    }
    std::swap(*write_pos, *(end - 1));
    return write_pos;
}

template<class InputIterator>
void QuickSort(InputIterator begin, InputIterator end) {
    if (begin + 1 < end) {
        auto pivot_pos = Partition(begin, end);
        QuickSort(begin, pivot_pos);
        QuickSort(pivot_pos + 1, end);
    }
}

template<class InputIterator>
void Merge(InputIterator output_begin, InputIterator begin1, InputIterator end1, InputIterator begin2, InputIterator end2) {
    while (begin1 != end1 && begin2 != end2) {
        if (*begin1 < *begin2) *(output_begin++) = *(begin1++);
        else *(output_begin++) = *(begin2++);
    }

    while (begin1 != end1) {
        *(output_begin++) = *(begin1++);
    }

    while (begin2 != end2) {
        *(output_begin++) = *(begin2++);
    }
}

template<class T>
void MergeSort(std::vector<T>& array) {
    auto begin = array.begin();
    auto end = array.end();
    if (begin + 1 >= end) return;
    if (end - begin == 2) {
        if (*begin > *(end - 1)) std::swap(*begin, *(end - 1));
        return;
    }
    auto pivot = begin + (end - begin) / 2;
    std::vector<T> left(begin, pivot);
    MergeSort(left);
    std::vector<T> right(pivot, end);
    MergeSort(right);
    Merge(begin, left.begin(), left.end(), right.begin(), right.end());
}

template<class Iterator>
void ShellSort(Iterator begin, Iterator end) {
    if (begin + 1 >= end) return;
    const int n = end - begin;

    for(int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++) {
            const auto data_to_move = *(begin + i);
            int j = i;
            for (;j - gap >= 0 && *(begin + j - gap) > data_to_move; j -= gap) {
                *(begin + j) = *(begin + j -gap);
            }
            *(begin + j) = data_to_move;
        }
    }
}