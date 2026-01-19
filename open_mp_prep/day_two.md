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

To test how the system handles unusual numbers, I forced the programme to run with 21 threads.

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

## 4. Practical Application: Prime Number Speed Test

To test performance, I created a benchmark to find as many prime numbers as possible in exactly 1 second. I compared a standard C++ implementation against an OpenMP implementation.

### 4.1. Baseline (No Parallelism)
I ran a standard single-threaded loop compiled with `-O3` optimisation.

**Code:**
```cpp
#include <iostream>
#include <cmath>
#include <chrono> 

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    using namespace std::chrono;
    int count = 0;   
    int num = 2;  
    auto start = high_resolution_clock::now();

    while (true) {
        if (isPrime(num)) count++;
        num++;
        auto now = high_resolution_clock::now();
        if (duration_cast<seconds>(now - start).count() >= 1) break;
    }
    std::cout << "Found " << count << " primes." << std::endl;
    std::cout << "Highest number checked: " << num << std::endl;
    return 0;
}
```

**Output:**
```text
Counting primes for 1 second...
Found 353760 primes in 1 second.
Highest number checked: 5081438
```

### 4.2. OpenMP Implementation (30 Threads)
I parallelised the workload using 30 threads. I used `atomic capture` to ensure threads could pick numbers from a shared counter without duplication.

**Code:**
```cpp
#include <math.h>
#include <iostream>
#include <omp.h> 

bool isPrime(int n){
    if (n <= 1) return false;
    for (int i = 2; i < (sqrt(n) + 1); i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    omp_set_num_threads(30);
    int count = 0;
    int next_num = 2;
    double start_time = omp_get_wtime();

    #pragma omp parallel
    {
        while (omp_get_wtime() - start_time < 1) {
            int my_num;
            #pragma omp atomic capture
            my_num = next_num++;
            
            if (isPrime(my_num)){
                #pragma omp atomic
                count++;
            }
        }
    }
    std::cout << "Count: " << count << std::endl;
    std::cout << "Checked up to: " << next_num << std::endl;
    std::cout << "Time: " << omp_get_wtime() - start_time << std::endl;
    return 0;
}
```

**Output:**
```text
Count: 905205
Checked up to: 13918717
Time: 1.00012
```

### 4.3. Performance Analysis
* **Baseline:** 353,760 primes found.
* **OpenMP (30 Threads):** 905,205 primes found.
* **Speedup:** ~2.56x.

Although I used 30 cores, the speedup was not 30x. This suggests a bottleneck known as **Atomic Contention**. The threads are spending significant time waiting to access the shared `next_num` variable (the critical section) rather than calculating. In future, increasing the "granularity" (batch size) of work could solve this.