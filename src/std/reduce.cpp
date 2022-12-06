#include "reduce.hpp"

#include <execution>
#include <numeric>

int sum_numbers_with_accumulate(const std::vector<int>& numbers)
{
    return std::accumulate(numbers.begin(), numbers.end(), 0);
}

int sum_numbers_with_reduce_seq(const std::vector<int>& numbers)
{
    return std::reduce(std::execution::seq, numbers.begin(), numbers.end());
}

int sum_numbers_with_reduce_unseq(const std::vector<int>& numbers)
{
    return std::reduce(std::execution::unseq, numbers.begin(), numbers.end());
}

int sum_numbers_with_reduce_par(const std::vector<int>& numbers)
{
    return std::reduce(std::execution::par, numbers.begin(), numbers.end());
}

int sum_numbers_with_reduce_par_unseq(const std::vector<int>& numbers)
{
    return std::reduce(std::execution::par_unseq, numbers.begin(), numbers.end());
}
