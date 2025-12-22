class Solution {
public:
    int countPrimes(int n) {
        // If n <= 2, there are no prime numbers less than n
        if (n <= 2) return 0;

        // prime[i] = 1 means i is prime
        // prime[i] = 0 means i is not prime
        vector<int> prime(n, 1);

        // 0 and 1 are not prime
        prime[0] = 0;
        prime[1] = 0;

        // Mark non-prime numbers using Sieve of Eratosthenes
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                // Mark all multiples of i as non-prime
                for (int j = i * 2; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }

        // Count all prime numbers less than n
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) cnt++;
        }

        return cnt;
    }
};

// TC:- O(n log logn ) why?? Although there are nested loops, each number is marked only by its prime divisors, resulting in a time complexity of O(n log log n).
// SC: O(n) — boolean array to mark primes