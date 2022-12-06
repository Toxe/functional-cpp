#include "accumulate.hpp"

#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

#include "../helpers/generators.hpp"

TEST_CASE("std::accumulate")
{
    SECTION("numbers")
    {
        const std::vector<int> numbers = generate_numbers(6);

        CHECK(sum_all_numbers(numbers) == 21);
        CHECK(sum_even_numbers(numbers) == 12);
        CHECK(multiply_numbers(numbers) == 720);
    }

    SECTION("strings")
    {
        const std::vector<std::string> strings = generate_strings(3);

        CHECK_THAT(concatenate_strings(strings), Catch::Matchers::Equals("value 1value 2value 3"));
        CHECK_THAT(concatenate_strings_with_delimiter(strings), Catch::Matchers::Equals("value 1, value 2, value 3"));
    }
}
