#pragma once

#include <string_view>

namespace check_unique_chars {

bool sorted_strings(const std::string_view& line);
bool bits(const std::string_view& line);
bool bits_and_early_return(const std::string_view& line);
bool bitset(const std::string_view& line);
bool bitset_and_early_return(const std::string_view& line);
bool counting_chars(const std::string_view& line);
bool counting_chars_and_early_return(const std::string_view& line);
bool unordered_set(const std::string_view& line, std::size_t bucket_size);

}  // namespace check_unique_chars
