//
// Created by alanp on 19/04/2019.
//
#include <benchmark/benchmark.h>
#include "../src/array.h"

const auto size = (1 << 18) + 1;

static void BM_Array_Set_Test(benchmark::State& state) {
    auto array = Array<int, size>();
    for(auto _ : state) {
        array.set(state.range(0), 1);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_Array_Set_Test) -> RangeMultiplier(2) -> Range(1<<10, 1<<18) -> Complexity();

static void BM_Array_Get_Test(benchmark::State& state) {
    auto array = Array<int, size>();
    for(auto _ : state) {
        array.get(state.range(0));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_Array_Get_Test) -> RangeMultiplier(2) -> Range(1<<10, 1<<18) -> Complexity();