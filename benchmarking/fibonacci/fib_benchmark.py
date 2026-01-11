import time

a, b = 0, 1
iterations = 0
MASK = 2**64 # Simulate 64-bit overflow

# Run for 1 second
start_time = time.perf_counter()
end_time = start_time + 1

while time.perf_counter() < end_time:
    # Unroll loop slightly to reduce time check overhead
    for _ in range(1000):
        a, b = b, (a + b) % MASK
    iterations += 1000

print(f"Python Iterations: {iterations}")
