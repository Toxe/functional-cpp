#pragma once

#include <vector>

int sum_numbers_with_accumulate(const std::vector<int>& numbers);
int sum_numbers_with_reduce_seq(const std::vector<int>& numbers);
int sum_numbers_with_reduce_unseq(const std::vector<int>& numbers);
int sum_numbers_with_reduce_par(const std::vector<int>& numbers);
int sum_numbers_with_reduce_par_unseq(const std::vector<int>& numbers);
