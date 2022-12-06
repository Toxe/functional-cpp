#include "benchmark/benchmark.h"

#include "../helpers/generators.hpp"
#include "accumulate.hpp"

static void BM_sum_all_numbers(benchmark::State& state)
{
    const std::vector<int> numbers = generate_numbers(1000);

    for (auto _ : state)
        benchmark::DoNotOptimize(sum_all_numbers(numbers));
}

static void BM_sum_even_numbers(benchmark::State& state)
{
    const std::vector<int> numbers = generate_numbers(1000);

    for (auto _ : state)
        benchmark::DoNotOptimize(sum_even_numbers(numbers));
}

static void BM_multiply_numbers(benchmark::State& state)
{
    const std::vector<int> numbers = generate_numbers(1000);

    for (auto _ : state)
        benchmark::DoNotOptimize(multiply_numbers(numbers));
}

static void BM_concatenate_strings(benchmark::State& state)
{
    const std::vector<std::string> strings = generate_strings(100);

    for (auto _ : state)
        benchmark::DoNotOptimize(concatenate_strings(strings));
}

static void BM_concatenate_strings_with_delimiter(benchmark::State& state)
{
    const std::vector<std::string> strings = generate_strings(100);

    for (auto _ : state)
        benchmark::DoNotOptimize(concatenate_strings_with_delimiter(strings));
}

BENCHMARK(BM_sum_all_numbers);
BENCHMARK(BM_sum_even_numbers);
BENCHMARK(BM_multiply_numbers);
BENCHMARK(BM_concatenate_strings);
BENCHMARK(BM_concatenate_strings_with_delimiter);
