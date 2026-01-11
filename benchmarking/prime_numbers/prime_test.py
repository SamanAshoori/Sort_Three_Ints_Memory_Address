#Import time to for 1 second
import time

#Creating as many prime numbers as I can in one second
def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def print_primes():
    nums_found = 0
    current_num = 1
    start_time = time.perf_counter()
    end_time = start_time + 1

    while time.perf_counter() < end_time:
        if is_prime(current_num):
            print(current_num)
            nums_found += 1
        current_num += 1
        
    print(f"Primes found in 1 second: {nums_found}")

# Example usage

print_primes()

#TO DO: LOOP 3 TIMES AND GET AVERAGE PRIMES CREATED IN 1 SECOND
