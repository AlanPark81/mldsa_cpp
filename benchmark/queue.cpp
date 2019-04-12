//
// Created by alanpark on 19. 4. 12.
//

#include <benchmark/benchmark.h>
#include "../src/queue.h"
#include <vector>


Queue<int> ConstructQueue(int64_t size) {
    Queue<int> q;

    for (int i = 0; i < size; ++i) {
        q.Enqueue(static_cast<int>(15));
    }
    return q;
}

static void BM_Queue_Enqueue(benchmark::State& state) {
    Queue<int> queue = ConstructQueue(state.range(0));
    for(auto _ : state) {
        queue.Enqueue(1);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_Queue_Enqueue) -> RangeMultiplier(2) -> Range(1<<10, 1<<18) -> Complexity();


static void BM_Queue_Dequeue(benchmark::State& state) {
    Queue<int> queue = ConstructQueue(state.range(0));
    for(auto _ : state) {
        if(!queue.empty()) queue.Dequeue();
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_Queue_Dequeue) -> RangeMultiplier(2) -> Range(1<<10, 1<<18) -> Complexity();
