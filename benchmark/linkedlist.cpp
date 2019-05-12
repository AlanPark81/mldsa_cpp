//
// Created by alanpark on 19. 4. 12.
//
#include <benchmark/benchmark.h>
#include "../src/linkedlist.h"

LinkedList<int> ConstructLinkedList(int64_t size) {
    LinkedList<int> list;

    for (int i = 0; i < size; ++i) {
        list.PushBack(static_cast<int>(15));
    }
    return list;
}

static void BM_LinkedList_Search(benchmark::State& state) {
    LinkedList<int> linkedList = ConstructLinkedList(state.range(0));
    for(auto _ : state) {
        if (linkedList.empty()) break;
        for(auto iter = linkedList.begin(); iter.valid(); iter.Next()) {
            if(iter.Next() == 16) break;
        }
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_LinkedList_Search) -> RangeMultiplier(2) -> Range(1<<10, 1<<18) -> Complexity();

static void BM_LinkedList_PushBack(benchmark::State& state) {
    LinkedList<int> linkedList;// = ConstructLinkedList(state.range(0));
    const int N = state.range(0);
    for(auto i = 0; i < N; i++) {
        linkedList.PushBack(i);
    }
    for(auto _ : state) {
        linkedList.PushBack(1);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_LinkedList_PushBack) -> RangeMultiplier(2) -> Range(1<<10, 1<<18) -> Complexity();