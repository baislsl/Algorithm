//
// Created by baislsl on 2025/8/1.
//

#ifndef MOD_HPP
#define MOD_HPP


template<typename T>
class Mod {
public:
    T mod;

    Mod(T mod) : mod(mod) {
    }

    Mod() : mod(std::numeric_limits<T>::max()) {
    }

    // ax + by = gcd(a, b)
    T extended_gcd(T a, T b, T &x, T &y) {
        if (b == 0) {
            x = 1, y = 0;
            return a;
        }
        T x1, y1;
        T g = extended_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return g;
    }

    // return x where ax = 1 MOD mod
    int mod_inverse_egcd(T a) {
        T x, y;
        T g = extended_gcd(a, mod, x, y);
        if (g != 1) {
            // 不互质，逆元不存在
            return -1;
        } else {
            return (x % mod + mod) % mod;
        }
    }

    T power(T a, T b) {
        T result = 1;
        a %= mod;
        while (b) {
            if (b & 1) result = result * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return result;
    }

    // a^(mod - 2) % mod
    T mod_inverse(T a) {
        return power(a, mod - 2);
    }

    vector<int> get_inverses(int n) {
        vector<int> inv(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            inv[i] = (long long) (mod - mod / i) * inv[mod % i] % mod;
        }
        return inv;
    }
};

/*

    Mod<long long> md2(1e9+7);
    _print(md2.mod_inverse(3));
    _print(md2.mod_inverse(13));

    Mod<long long> md(11);
    auto v = md.mod_inverse(3);
    auto v2 = md.mod_inverse_egcd(3);
    _print(v, v2);

    md.mod = 13;
    auto v3 = md.get_inverses(10);
    _print(v3);


*/

#endif //MOD_HPP
