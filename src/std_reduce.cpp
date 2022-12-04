#include <execution>
#include <iostream>
#include <numeric>

#include "benchmark.hpp"
#include "generators.hpp"

int sum_numbers_with_accumulate(const std::vector<int>& numbers)
{
    const Benchmark benchmark{"accumulate"};

    return std::accumulate(numbers.begin(), numbers.end(), 0);
}

int sum_numbers_with_reduce_seq(const std::vector<int>& numbers)
{
    const Benchmark benchmark{"reduce (sequenced)"};

    return std::reduce(std::execution::seq, numbers.begin(), numbers.end());
}

int sum_numbers_with_reduce_unseq(const std::vector<int>& numbers)
{
    const Benchmark benchmark{"reduce (unsequenced)"};

    return std::reduce(std::execution::unseq, numbers.begin(), numbers.end());
}

int sum_numbers_with_reduce_par(const std::vector<int>& numbers)
{
    const Benchmark benchmark{"reduce (parallel)"};

    return std::reduce(std::execution::par, numbers.begin(), numbers.end());
}

int sum_numbers_with_reduce_par_unseq(const std::vector<int>& numbers)
{
    const Benchmark benchmark{"reduce (parallel unsequenced)"};

    return std::reduce(std::execution::par_unseq, numbers.begin(), numbers.end());
}

int main()
{
    const std::vector<int> numbers = generate_numbers(100'000'000);

    std::cout << sum_numbers_with_accumulate(numbers) << '\n';
    std::cout << sum_numbers_with_reduce_seq(numbers) << '\n';
    std::cout << sum_numbers_with_reduce_unseq(numbers) << '\n';
    std::cout << sum_numbers_with_reduce_par(numbers) << '\n';
    std::cout << sum_numbers_with_reduce_par_unseq(numbers) << '\n';
}
