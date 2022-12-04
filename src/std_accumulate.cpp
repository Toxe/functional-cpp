#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

const std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
const std::vector<std::string> strings = {"one", "two", "three", "four"};

int sum_all_numbers()
{
    return std::accumulate(numbers.begin(), numbers.end(), 0);
}

int sum_even_numbers()
{
    return std::accumulate(numbers.begin(), numbers.end(), 0,
        [](int current_sum, const int n) {
            return (n % 2 == 0) ? current_sum + n : current_sum;
        });
}

int multiply_numbers()
{
    return std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies{});
}

std::string concatenate_strings()
{
    return std::accumulate(strings.begin(), strings.end(), std::string{});
}

std::string concatenate_strings_with_delimiter()
{
    return std::accumulate(std::next(strings.begin()), strings.end(), strings.front(),
        [](const std::string& accu, const std::string& s) {
            return accu + ", " + s;
        });
}

int main()
{
    std::cout << sum_all_numbers() << '\n';
    std::cout << sum_even_numbers() << '\n';
    std::cout << multiply_numbers() << '\n';
    std::cout << concatenate_strings() << '\n';
    std::cout << concatenate_strings_with_delimiter() << '\n';
}
