# 🧪 Stress Testing: Finding Bugs Fast

Stress testing is the process of running two solutions against the same random input to find a case where your "fast" solution fails.

## 1. Why Stress Test?
If your code passes samples but gives **Wrong Answer (WA)** on the judge, and you can't find the bug, a stress tester will find the exact small input where your code fails.

## 2. Component Requirements
1.  **Solution (A)**: Your fast code that is currently failing.
2.  **Brute Force (B)**: A slow but 100% correct solution (e.g., $O(N^2)$).
3.  **Generator (G)**: A script that generates random input based on constraints.
4.  **Script (S)**: A bash/python script to run them in a loop.

## 3. Simple Bash Stress Tool
Create a file `stress.sh`:

```bash
# Compile everything
g++ -O3 solution.cpp -o sol
g++ -O3 brute.cpp -o brute
g++ -O3 gen.cpp -o gen

for((i = 1; ; ++i)); do
    ./gen $i > input_file      # Generate random input
    ./sol < input_file > out1  # Run your code
    ./brute < input_file > out2 # Run slow code
    
    if diff -Z out1 out2 > /dev/null; then
        echo "Test $i: Passed"
    else
        echo "Test $i: FAILED!"
        echo "--- Input ---"
        cat input_file
        echo "--- Expected ---"
        cat out2
        echo "--- Found ---"
        cat out1
        break
    fi
done
```

## 4. Tips for Good Generators
*   Use the current time as a seed: `srand(time(NULL))`.
*   Start with **small constraints** (e.g., $N=10$). Most bugs appear even in tiny cases.
*   Generate "edge cases" (all numbers 0, all numbers equal, very large numbers).
