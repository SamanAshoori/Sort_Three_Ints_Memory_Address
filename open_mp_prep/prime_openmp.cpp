#include <math.h>
#include <iostream>
#include <omp.h> 


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
    omp_set_num_threads(25);
    int count = 0;
    int next_num = 2;
    double start_time = omp_get_wtime();

    #pragma omp parallel
    {
        while (omp_get_wtime() - start_time < 1)
        {
            int my_num;
            #pragma omp atomic capture
            {
                my_num = next_num++;
            }
            if (isPrime(my_num)){
                #pragma omp atomic
                count++;
            }
        }
    }

    //LETS USE 25 CORS
    std::cout << "Count: " << count << std::endl;
    std::cout << "Checked up to: " << next_num << std::endl;
    std::cout << "Time: " << omp_get_wtime() - start_time << std::endl;
    return 0;
}
