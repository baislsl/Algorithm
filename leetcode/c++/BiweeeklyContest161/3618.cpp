//
// Created by baislsl on 2025/7/19.
//

#include "common.hpp"

using namespace std;

class PrimeTable {
public:
    vector<int> primes; // 2， 3， 5, ...
    vector<bool> isPrime; // false, false, true, true, false, true, ...
    int n;

    PrimeTable(int n) : isPrime(n + 1, true), n(n) {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) primes.push_back(i);
            for (int p: primes) {
                if (p * i > n) break;
                isPrime[p * i] = false;
                if (i % p == 0) break;
            }
        }
    }

    map<int, int> factorize(int x) const {
        assert(n >= static_cast<double>(x)/n);
        map<int, int> factors;
        for (int p: primes) {
            if (p * p > x) break;
            while (x % p == 0) {
                factors[p]++;
                x /= p;
            }
        }
        if (x > 1) factors[x] = 1;
        return factors;
    }
};

class Solution {
public:
    using ll = long long;

    long long splitArray(const vector<int> &nums) {
        PrimeTable pt(100005);
        ll a = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (pt.isPrime[i]) {
                a += nums[i];
            } else {
                a -= nums[i];
            }
        }
        return abs(a);
    }
};

int main() {
    Solution s;
    _print(s.splitArray({2, 3, 4}));
    _print(s.splitArray({-1, 5, 7, 0}));
}
