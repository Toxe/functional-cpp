#include "reduce.hpp"

#include "catch2/catch_test_macros.hpp"

#include "../helpers/generators.hpp"

TEST_CASE("std::reduce")
{
    SECTION("numbers")
    {
        const std::vector<int> numbers = generate_numbers(10);

        CHECK(sum_numbers_with_accumulate(numbers) == 55);
        CHECK(sum_numbers_with_reduce_seq(numbers) == 55);
        CHECK(sum_numbers_with_reduce_unseq(numbers) == 55);
        CHECK(sum_numbers_with_reduce_par(numbers) == 55);
        CHECK(sum_numbers_with_reduce_par_unseq(numbers) == 55);
    }
}
