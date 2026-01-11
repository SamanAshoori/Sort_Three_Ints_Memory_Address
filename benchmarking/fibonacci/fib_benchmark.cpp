#include <iostream>
#include <chrono>

int main() {
    unsigned long long a = 0;
    unsigned long long b = 1;
    unsigned long long iterations = 0;

    // Run for 1 second
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + std::chrono::seconds(1);

    // Loop until time is up
    // We check time every 1000 iterations to minimize clock overhead
    while (std::chrono::high_resolution_clock::now() < end) {
        for (int i = 0; i < 1000; ++i) {
            unsigned long long next = a + b;
            a = b;
            b = next;
        }
        iterations += 1000;
    }

    std::cout << "C++ Iterations: " << iterations << std::endl;
    // Print the final value to prevent the compiler from optimizing away the loop math
    std::cout << "Final value (overflowed): " << a << std::endl;
    return 0;
}
