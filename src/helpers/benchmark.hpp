#pragma once

#include <chrono>
#include <iostream>
#include <string_view>

class Benchmark {
public:
    explicit Benchmark(std::string_view title) : title_{title}
    {
        start_ = std::chrono::steady_clock::now();
    }

    ~Benchmark()
    {
        const auto diff = std::chrono::steady_clock::now() - start_;
        std::cout << title_ << ": " << diff << '\n';
    }

private:
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> start_;
    std::string_view title_;
};
