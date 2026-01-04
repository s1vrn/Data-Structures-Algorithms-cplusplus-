# 🎲 Probability and Expectation in CP

Many advanced CP problems involve calculating the "Expected Value". 
The key is understanding that **Expectation is Linear**.

## 1. Expected Value Basics
If an event $X$ has outcomes $x_1, x_2, \dots$ with probabilities $p_1, p_2, \dots$, the Expected Value $E[X]$ is:
$$E[X] = \sum x_i p_i$$

### Example: Rolling a Fair Die
Outcomes: $\{1, 2, 3, 4, 5, 6\}$, each with $p = 1/6$.
$$E[X] = (1+2+3+4+5+6) / 6 = 3.5$$

## 2. Linearity of Expectation (Super Power)
The expected value of a sum is the sum of expected values:
$$E[X + Y] = E[X] + E[Y]$$
**Crucially, this holds even if X and Y are dependent!**

### Example: Number of Fixed Points in a Permutation
If you shuffle $N$ hats and return them, how many people get their own hat back on average?
*   Let $X_i$ be an indicator variable: $X_i = 1$ if person $i$ gets their hat, 0 otherwise.
*   $P(X_i = 1) = 1/N$.
*   $E[X_i] = 1/N$.
*   Total expected value $E[X] = E[X_1 + \dots + X_N] = E[X_1] + \dots + E[X_N] = N \times (1/N) = \mathbf{1}$.
*   Always 1, no matter how big $N$ is!

## 3. Geometric Distribution (Waiting Time)
If you succeed with probability $p$, the expected number of attempts until the first success is:
$$E[\text{attempts}] = \frac{1}{p}$$

### Example: Coupon Collector Problem
How many die rolls to see all 6 faces?
*   First face: $p_1 = 6/6 \rightarrow E_1 = 1$.
*   Second face: $p_2 = 5/6 \rightarrow E_2 = 6/5$.
*   ...
*   Total $E = \sum 6/i = 14.7$.

## 4. Tips for CP
1.  **Iterative DP**: Define $dp[i]$ as the expected value to finish from state $i$.
2.  **Precision**: Always use `double` or `long double`. Use `fixed` and `setprecision(10)` for output.
3.  **Modulo inverse**: Sometimes problems ask for expected value modulo $10^9+7$. Since $E = P/Q$, calculate $P \times Q^{-1} \pmod M$.
