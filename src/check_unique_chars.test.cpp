#include "catch2/catch_test_macros.hpp"

#include "check_unique_chars.hpp"

namespace check_unique_chars {

TEST_CASE("check_unique_chars")
{
    const std::vector<std::string> all_unique = {
        "vwbj",
        "pdvj",
        "rfnt",
        "zqfr",
        "qmgbljsphdztnv",
        "vbhsrlpgdmjqwf",
        "ldpwncqszvftbr",
        "wmzdfjlvtqnbhc",
        "jwzlrfnpqdbhtm",
    };

    const std::vector<std::string> repeating = {
        "bvwb",
        "ppdv",
        "frfn",
        "zzqf",
        "pqmgbljsphdztn",
        "gvbhsrlpgdmjqw",
        "qldpwncqszvftb",
        "fwmzdfjlvtqnbh",
        "ljwzlrfnpqdbht",
    };

    SECTION("sorted_strings()")
    {
        for (const auto& s : all_unique)
            CHECK(sorted_strings(s) == true);

        for (const auto& s : repeating)
            CHECK(sorted_strings(s) == false);
    }

    SECTION("bits()")
    {
        for (const auto& s : all_unique)
            CHECK(bits(s) == true);

        for (const auto& s : repeating)
            CHECK(bits(s) == false);
    }

    SECTION("bits_and_early_return()")
    {
        for (const auto& s : all_unique)
            CHECK(bits_and_early_return(s) == true);

        for (const auto& s : repeating)
            CHECK(bits_and_early_return(s) == false);
    }

    SECTION("bitset()")
    {
        for (const auto& s : all_unique)
            CHECK(bitset(s) == true);

        for (const auto& s : repeating)
            CHECK(bitset(s) == false);
    }

    SECTION("bitset_and_early_return()")
    {
        for (const auto& s : all_unique)
            CHECK(bitset_and_early_return(s) == true);

        for (const auto& s : repeating)
            CHECK(bitset_and_early_return(s) == false);
    }

    SECTION("counting_chars()")
    {
        for (const auto& s : all_unique)
            CHECK(counting_chars(s) == true);

        for (const auto& s : repeating)
            CHECK(counting_chars(s) == false);
    }

    SECTION("counting_chars_and_early_return()")
    {
        for (const auto& s : all_unique)
            CHECK(counting_chars_and_early_return(s) == true);

        for (const auto& s : repeating)
            CHECK(counting_chars_and_early_return(s) == false);
    }

    SECTION("unordered_set()")
    {
        for (const auto& s : all_unique)
            CHECK(unordered_set(s, 32) == true);

        for (const auto& s : repeating)
            CHECK(unordered_set(s, 32) == false);
    }
}

}  // namespace check_unique_chars
