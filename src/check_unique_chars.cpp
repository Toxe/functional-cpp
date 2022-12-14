/*
 * Check if all lowercase, alphabetic characters ('a'-'z') in a string are unique.
 *
 * Inspired by Advent of Code 2022, day 6: https://adventofcode.com/2022/day/6
 */

#include "check_unique_chars.hpp"

#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cassert>
#include <string>
#include <unordered_set>

namespace check_unique_chars {

bool sorted_strings(const std::string_view& line)
{
    std::string s{line};
    std::sort(s.begin(), s.end());

    return std::adjacent_find(s.begin(), s.end()) == s.end();
}

bool bits(const std::string_view& line)
{
    uint32_t bits = 0;

    for (const char c : line)
        bits |= 1 << (static_cast<std::size_t>(c - 'a'));

    return std::popcount(bits) == std::ssize(line);
}

bool bits_and_early_return(const std::string_view& line)
{
    uint32_t bits = 0;

    for (const char c : line) {
        const uint32_t bit = 1 << (static_cast<std::size_t>(c - 'a'));

        if ((bits & bit) == bit)
            return false;

        bits |= bit;
    }

    return std::popcount(bits) == std::ssize(line);
}

bool bitset(const std::string_view& line)
{
    std::bitset<26> bits;

    for (const char c : line)
        bits[static_cast<std::size_t>(c - 'a')] = true;

    return bits.count() == line.size();
}

bool bitset_and_early_return(const std::string_view& line)
{
    std::bitset<26> bits;

    for (const char c : line) {
        if (bits[static_cast<std::size_t>(c - 'a')])
            return false;

        bits[static_cast<std::size_t>(c - 'a')] = true;
    }

    return bits.count() == line.size();
}

bool counting_chars(const std::string_view& line)
{
    assert(line.size() < 256);

    std::array<uint8_t, 26> counters{};

    for (const char c : line)
        ++counters[static_cast<std::size_t>(c - 'a')];

    return std::none_of(counters.begin(), counters.end(), [](auto count) { return count > 1; });
}

bool counting_chars_and_early_return(const std::string_view& line)
{
    assert(line.size() < 256);

    std::array<uint8_t, 26> counters{};

    for (const char c : line)
        if (++counters[static_cast<std::size_t>(c - 'a')] > 1)
            return false;

    return true;
}

bool unordered_set(const std::string_view& line, size_t bucket_size)
{
    const std::unordered_set<char> set{line.begin(), line.end(), bucket_size};

    return set.size() == line.size();
}

}  // namespace check_unique_chars
