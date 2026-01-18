day_two has to be my last day as my intro to OpenMP course starts tomorrow - however  I might as well try some stuff out

```Cpp
#include <iostream>
#include <omp.h> // The OpenMP header

int main() {
    // Set the desired number of threads (optional, defaults to CPU core count)
    omp_set_num_threads(8);

    // Begin the parallel region
    #pragma omp parallel
    {
        // Get the unique ID of the current thread
        int thread_id = omp_get_thread_num();
        
        // Get the total number of threads created
        int total_threads = omp_get_num_threads();

        printf("Hello World from thread %d of %d\n", thread_id, total_threads);
    } 
    // End of parallel region - all threads join back here

    return 0;
}
```

## Output

output from this code
(base) saman@Saman-MSI-Laptop:~/dev/cplusplus/Becoming_Cracked_CPP/open_mp_prep$ g++ -fopenmp day_two.cpp -o day_two
(base) saman@Saman-MSI-Laptop:~/dev/cplusplus/Becoming_Cracked_CPP/open_mp_prep$ ./day_two
Hello World from thread 7 of 8
Hello World from thread 1 of 8
Hello World from thread 2 of 8
Hello World from thread 3 of 8
Hello World from thread 5 of 8
Hello World from thread 0 of 8
Hello World from thread 6 of 8
Hello World from thread 4 of 8