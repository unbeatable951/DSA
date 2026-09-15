class Solution {
public:
    int numPrimeArrangements(int n) {
        int primeCount = 0;
        
        // Count primes up to n
        for (int i = 2; i <= n; ++i) {
            if (isPrime(i)) {
                primeCount++;
            }
        }
        
        long long MOD = 1e9 + 7;
        long long result = 1;
        
        // Multiply permutations of prime numbers (p!)
        for (int i = 1; i <= primeCount; ++i) {
            result = (result * i) % MOD;
        }
        
        // Multiply permutations of non-prime numbers ((n - p)!)
        for (int i = 1; i <= n - primeCount; ++i) {
            result = (result * i) % MOD;
        }
        
        return result;
    }

private:
    bool isPrime(int k) {
        if (k < 2) return false;
        for (int i = 2; i * i <= k; ++i) {
            if (k % i == 0) return false;
        }
        return true;
    }
};