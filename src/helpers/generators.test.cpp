#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_container_properties.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

#include "generators.hpp"

TEST_CASE("generate_numbers()")
{
    SECTION("returns a vector of numbers")
    {
        const auto numbers = generate_numbers(10);

        REQUIRE_THAT(numbers, Catch::Matchers::SizeIs(10));

        for (int i = 0; i < 10; ++i)
            CHECK(numbers[i] == i + 1);
    }
}

TEST_CASE("generate_strings()")
{
    SECTION("returns a vector of strings")
    {
        const auto strings = generate_strings(5);

        REQUIRE_THAT(strings, Catch::Matchers::SizeIs(5));

        CHECK_THAT(strings[0], Catch::Matchers::Equals("value 1"));
        CHECK_THAT(strings[1], Catch::Matchers::Equals("value 2"));
        CHECK_THAT(strings[2], Catch::Matchers::Equals("value 3"));
        CHECK_THAT(strings[3], Catch::Matchers::Equals("value 4"));
        CHECK_THAT(strings[4], Catch::Matchers::Equals("value 5"));
    }
}
