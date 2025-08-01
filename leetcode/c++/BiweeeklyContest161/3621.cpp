//
// Created by baislsl on 2025/7/19.
//

#include "common.hpp"

using namespace std;


template<typename T>
class Comb {
public:
    vector<vector<T> > C;
    T mod;

    Comb(int n) : Comb(n, -1) {
    }

    Comb(int n, T mod)
        : C(n, vector<T>(n, static_cast<T>(0))), mod(mod) {
        for (int i = 0; i < n; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
                assert(C[i][j] > 0);

                if (mod > 0) C[i][j] %= mod;
            }
        }
    }

    T operator()(int m, int n) {
        return C[m][n];
    }
};


class Solution {
public:
    using ll = long long;

    long long popcountDepth(long long n, int k) {
        vector<int> tb{-100};
        for (int i = 1; i <= 64; i++) {
            int p = i, d = 0;
            while (p != 1) {
                p = __builtin_popcount(p);
                d++;
            }
            tb.push_back(d);
        }

        Comb<ll> C(65);

        if (k == 0) return n >= 1 ? 1 : 0;
        int pv = __builtin_popcountll(n);
        ll ans = 0;
        if (n <= 64) { if (tb[n] == k) ans++; } else if (1 + tb[pv] == k) ans++;

        ll m = n & (n - 1);
        // 10100
        // 10000
        // 0 - 100

        while (true) {
            // [m, n)
            int cnt = __builtin_popcountll(m);
            int j = 0;
            while (((1LL << j) & n) == 0) j++;
            for (int i = 0; i <= j; i++) {
                if (tb[i + cnt] + 1 == k) {
                    if (n != 1) {
                        ans += C(j, i);
                        if (n == (1LL << j) && i == 1 && k != 0) {
                            ans--;
                        }
                    }
                }
            }
            n = m;
            m = n & (n - 1);
            if (n == 0) break;
        }
        return ans;
    }
};

int main() {
    Solution s;
    auto v = __builtin_popcountll(4294967296);
    _print(s.popcountDepth(2, 0));
    _print(s.popcountDepth(6356378721, 3));
    _print(s.popcountDepth(5182394922, 1));
    _print(s.popcountDepth(8, 1));
    _print(s.popcountDepth(16, 2));
    _print(s.popcountDepth(1, 1));
    _print(s.popcountDepth(1, 0));
    _print(s.popcountDepth(4, 1));
    _print(s.popcountDepth(7, 2));
}
