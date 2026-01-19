# Becoming_Cracked_CPP

This monorepo documents my trajectory from absolute zero to becoming cracked at C++.



We maintain W motion only.

## Project Index

The repository is organised as a monorepo. As my proficiency increases, more complex directories will be initialised. I've been busy.

| Project Name | Description | Key Concepts |
| :--- | :--- | :--- |
| **Sort_Three_Ints** | A programme that takes three integers and sorts them in ascending order using direct memory manipulation. | Pointers, dereferencing, conditional logic. |
| **Rock_Paper_Scissors** | A standard console-based implementation of the Rock, Paper, Scissors game. | Input handling, randomisation, control flow. |
| **Hangman** | The classic word-guessing game. Probably involving a lot of `std::string` manipulation. | String handling, loops, user input. |
| **writing_to_file_reading** | A venture into the exciting world of file I/O. Reads from a file, writes to a file, the whole shebang. | `fstream`, file streams, error handling. |
| **workingWithClasses** | My first foray into proper grown-up programming. It's a class project, literally. | Classes, objects, encapsulation. |
| **stack_heap** | A project to understand the fundamental differences between the stack and the heap. Also, a sub-project on transferring ownership. | Memory allocation, `new`/`delete`, pointers, ownership. |
| **header_files** | A project to figure out how to split code into multiple files without the compiler having a meltdown. | Header guards, forward declarations, linking. |
| **benchmarking** | Seeing if my C++ is faster than my Python. Spoiler: it probably is. Contains Fibonacci and prime number tests. | Performance measurement, optimisation. |
| **open_mp_prep** | My notes and code from the "Intro to OpenMP" course. Still ongoing, wish me luck. | Parallel programming, multi-threading, `#pragma omp`. |

## Progression

I am currently in the foundational phase, but I'm making moves. Future additions will explore:

*   Object-Oriented Programming principles (in progress).
*   Advanced memory management and smart pointers (peeking at it).
*   Multi-threading and concurrency (in progress with OpenMP).

## Bonus Zone

A few interesting artefacts from my journey so far:

*   **The executables:** I'm compiling on Linux (Ubuntu, to be precise). The executables are included for posterity, even if they don't have a fancy `.exe` extension.
*   **The Python scripts:** Found lurking in the `benchmarking` directory. They are there to prove that C++ is, in fact, faster. That's the theory, anyway.
*   **`test_program.cpp`:** A handy little file that checks what C++ version my g++ compiler is using. No more guessing games.