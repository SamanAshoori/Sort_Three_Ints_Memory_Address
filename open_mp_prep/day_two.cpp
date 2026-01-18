#include <iostream>
#include <omp.h> // The OpenMP header

int main() {
    // Set the desired number of threads (optional, defaults to CPU core count)
    omp_set_num_threads(4);

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