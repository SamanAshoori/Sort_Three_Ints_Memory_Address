#include <iostream>
#include <cmath>
#include <chrono> 

bool isPrime(int n) {
    if (n <= 1) return false;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    using namespace std::chrono;

    int count = 0;   
    int num = 2;  
    
    std::cout << "Counting primes for 1 second..." << std::endl;

    auto start = high_resolution_clock::now();

    while (true) {
        if (isPrime(num)) {
            count++;
        }
        num++;
        
        auto now = high_resolution_clock::now();
        
        auto duration = duration_cast<seconds>(now - start);

        if (duration.count() >= 1) {
            break;
        }
    }

    std::cout << "Found " << count << " primes in 1 second." << std::endl;
    std::cout << "Highest number checked: " << num << std::endl;

    return 0;
}