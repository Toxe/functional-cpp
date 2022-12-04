#include <functional>
#include <iostream>
#include <numeric>

#include "generators.hpp"

int sum_all_numbers(const std::vector<int>& numbers)
{
    return std::accumulate(numbers.begin(), numbers.end(), 0);
}

int sum_even_numbers(const std::vector<int>& numbers)
{
    return std::accumulate(numbers.begin(), numbers.end(), 0,
        [](int current_sum, const int n) {
            return (n % 2 == 0) ? current_sum + n : current_sum;
        });
}

int multiply_numbers(const std::vector<int>& numbers)
{
    return std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies{});
}

std::string concatenate_strings(const std::vector<std::string>& strings)
{
    return std::accumulate(strings.begin(), strings.end(), std::string{});
}

std::string concatenate_strings_with_delimiter(const std::vector<std::string>& strings)
{
    return std::accumulate(std::next(strings.begin()), strings.end(), strings.front(),
        [](const std::string& accu, const std::string& s) {
            return accu + ", " + s;
        });
}

int main()
{
    const std::vector<int> numbers = generate_numbers(5);
    const std::vector<std::string> strings = generate_strings(5);

    std::cout << sum_all_numbers(numbers) << '\n';
    std::cout << sum_even_numbers(numbers) << '\n';
    std::cout << multiply_numbers(numbers) << '\n';
    std::cout << concatenate_strings(strings) << '\n';
    std::cout << concatenate_strings_with_delimiter(strings) << '\n';
}
