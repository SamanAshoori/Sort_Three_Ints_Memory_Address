# Day Two: OpenMP Preparation

This is the final practice session before the formal OpenMP course begins tomorrow. The focus is on setting up the environment and testing basic thread commands.

## 1. Basic Hello World

The code below sets up a standard OpenMP "Hello World". It manually sets the thread count to 8, ignoring the default settings of the hardware.

### Source Code

```cpp
#include <iostream>
#include <omp.h> // The OpenMP header

int main() {
    // Set the desired number of threads (optional)
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

### Output

Compiled using `g++` with the `-fopenmp` flag.

```text
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
```

## 2. Processor Count and Custom Threads

I used `omp_get_num_procs()` to check the hardware and confirmed the machine has **32 logical processors**. 

To test how the system handles unusual numbers, I forced the programme to run with 21 threads (get it cause 21 is funny).

### Code Snippet

```cpp
int num_procs = omp_get_num_procs();
printf("Number of processors: %d\n", num_procs);
```

### Output (21 Threads)

```text
Hello World from thread 2 of 21
Hello World from thread 12 of 21
Hello World from thread 19 of 21
Hello World from thread 17 of 21
Hello World from thread 18 of 21
Hello World from thread 0 of 21
Hello World from thread 3 of 21
Hello World from thread 5 of 21
Hello World from thread 1 of 21
Hello World from thread 6 of 21
Hello World from thread 8 of 21
Hello World from thread 4 of 21
Hello World from thread 7 of 21
Hello World from thread 16 of 21
Hello World from thread 15 of 21
Hello World from thread 20 of 21
Hello World from thread 14 of 21
Hello World from thread 9 of 21
Hello World from thread 10 of 21
Hello World from thread 11 of 21
Hello World from thread 13 of 21
```

## 3. Note on Execution Order

You will notice the output is not sequential (e.g., Thread 2 prints before Thread 0). 

This is standard behaviour in parallel programming. The operating system schedules threads independently, so they "race" to print to the screen. The order will likely change every time the code is run.