//
// Created by baislsl on 2025/7/24.
//

#ifndef COMB_HPP
#define COMB_HPP
#include <vector>
#include <assert.h>
using namespace std;

/*
Comb<long long> C(65);
Comb<int> C(33);
Comb<int> C(100, 1e9+7);

C(32, 16)
 */

template<typename T>
class Comb {
private:
    vector<vector<T> > C;
    T mod;

public:
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


#endif //COMB_HPP
