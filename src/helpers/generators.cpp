#include "generators.hpp"

#include <numeric>
#include <sstream>

std::vector<int> generate_numbers(int count)
{
    std::vector<int> numbers(count);
    std::iota(numbers.begin(), numbers.end(), 1);

    return numbers;
}

std::vector<std::string> generate_strings(int count)
{
    std::vector<std::string> strings(count);

    for (int i = 0; i < count; ++i) {
        std::stringstream sstream;
        sstream << "value " << i + 1;
        strings[i] = sstream.str();
    }

    return strings;
}
