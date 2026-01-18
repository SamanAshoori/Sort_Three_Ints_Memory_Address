#include <math.h>
#include <iostream>


bool isPrime(int n){
    if (n <= 1)
        return false;
    for (int i = 2; i < (sqrt(n) + 1); i++)
        if (n % i == 0)
            return false;
    return true;
    
}

void printPrimes(int n){
    for (int i = 2; i <= n; i++)
        if (isPrime(i))
            std::cout << i << " ";
}


int main(){
    printPrimes(50);
    std::cout << std::endl;
    return 0;
}
