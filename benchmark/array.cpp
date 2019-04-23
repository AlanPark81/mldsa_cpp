//
// Created by alanp on 19/04/2019.
//
#include <benchmark/benchmark.h>
#include "../src/array.h"


static void BM_Array_Set_Test(benchmark::State& state) {
    auto array = Array<int>((size_t)state.range(0) + 1);
    for(auto _ : state) {
        array.set((size_t)state.range(0), 1);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_Array_Set_Test) -> RangeMultiplier(2) -> Range(1<<10, 1<<18) -> Complexity();

static void BM_Array_Get_Test(benchmark::State& state) {
    auto array = Array<int>((size_t)state.range(0) + 1);
    for(auto _ : state) {
        array.get((size_t)state.range(0));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_Array_Get_Test) -> RangeMultiplier(2) -> Range(1<<10, 1<<18) -> Complexity();

static void BM_Array_Init_Complexity_Test(benchmark::State& state) {
    for(auto _ : state) {
        auto array = Array<int>((size_t)state.range(0) + 1);
        array.set((size_t)state.range(0), 1);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_Array_Init_Complexity_Test) -> RangeMultiplier(2) -> Range(1<<10, 1<<20) -> Complexity();

static void BM_Array_NoInit_Complexity_Test(benchmark::State& state) {
    for(auto _ : state) {
        auto array = new int[state.range(0) + 1];
        array[state.range(0)] = 1;
        delete[] array;
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_Array_NoInit_Complexity_Test) -> RangeMultiplier(2) -> Range(1<<10, 1<<20) -> Complexity();