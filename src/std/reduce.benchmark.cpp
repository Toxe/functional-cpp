#include "benchmark/benchmark.h"

#include "../helpers/generators.hpp"
#include "reduce.hpp"

constexpr int count = 10'000'000;

static void BM_sum_numbers_with_accumulate(benchmark::State& state)
{
    const std::vector<int> numbers = generate_numbers(count);

    for (auto _ : state)
        benchmark::DoNotOptimize(sum_numbers_with_accumulate(numbers));
}

static void BM_sum_numbers_with_reduce_seq(benchmark::State& state)
{
    const std::vector<int> numbers = generate_numbers(count);

    for (auto _ : state)
        benchmark::DoNotOptimize(sum_numbers_with_reduce_seq(numbers));
}

static void BM_sum_numbers_with_reduce_unseq(benchmark::State& state)
{
    const std::vector<int> numbers = generate_numbers(count);

    for (auto _ : state)
        benchmark::DoNotOptimize(sum_numbers_with_reduce_unseq(numbers));
}

static void BM_sum_numbers_with_reduce_par(benchmark::State& state)
{
    const std::vector<int> numbers = generate_numbers(count);

    for (auto _ : state)
        benchmark::DoNotOptimize(sum_numbers_with_reduce_par(numbers));
}

static void BM_sum_numbers_with_reduce_par_unseq(benchmark::State& state)
{
    const std::vector<int> numbers = generate_numbers(count);

    for (auto _ : state)
        benchmark::DoNotOptimize(sum_numbers_with_reduce_par_unseq(numbers));
}

BENCHMARK(BM_sum_numbers_with_accumulate);
BENCHMARK(BM_sum_numbers_with_reduce_seq);
BENCHMARK(BM_sum_numbers_with_reduce_unseq);
BENCHMARK(BM_sum_numbers_with_reduce_par);
BENCHMARK(BM_sum_numbers_with_reduce_par_unseq);
