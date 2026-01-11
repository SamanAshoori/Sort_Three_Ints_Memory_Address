#Creating as many prime numbers as I can in one second
def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def print_primes(n):
    for num in range(2, n + 1):
        if is_prime(num):
            print(num)

# Example usage
N = 50
print_primes(N)