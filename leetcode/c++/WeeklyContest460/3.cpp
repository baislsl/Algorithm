#include "common.hpp"

using namespace std;

class PrimeTable {
private:
    vector<bool> isPrime; // false, false, true, true, false, true, ...

public:
    vector<int> primes; // 2， 3， 5, ...
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

    bool isP(int x) const {
        assert(n >= static_cast<double>(x)/n);
        if (x < isPrime.size()) return isPrime[x];

        for (auto p: primes) {
            if (p * p > x) return true;
            if (x % p == 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    int minJumps(const vector<int> &ns) {
        int n = ns.size();
        PrimeTable pt(1e3 + 3);
        vector<bool> fg(n, false);
        set<int> st;
        map<int, vector<int>> pm;
        for (int i = 0; i < n; ++i) {
            st.insert(i);
            auto fc = pt.factorize(ns[i]);
            for (auto [p, cnt]: fc) {
                pm[p].push_back(i);
            }
        }


        set<int> cur;
        cur.insert(0);
        int step = 0;
        while (!cur.empty()) {
            set<int> ncur;
            for (auto idx: cur) {
                if (idx == n - 1) return step;
                fg[idx] = true;
                st.erase(idx);
            }

            for (auto idx: cur) {
                if (idx != n - 1 && !fg[idx + 1]) {
                    ncur.insert(idx + 1);
                }
                if (idx != 0 && !fg[idx - 1]) {
                    ncur.insert(idx - 1);
                }
                if (pt.isP(ns[idx])) {
                    for (auto i: pm[ns[idx]]) {
                        if (!fg[i] && ns[i] % ns[idx] == 0) {
                            ncur.insert(i);
                        }
                    }
                }
            }

            swap(cur, ncur);
            step++;
        }
        return -1;
    }

    int minJumps2(const vector<int> &ns) {
        int n = ns.size();
        PrimeTable pt(1e3 + 3);
        vector<bool> fg(n, false);
        set<int> st;
        for (int i = 0; i < n; ++i) st.insert(i);
        queue<pair<int, int> > q;

        q.push(make_pair(0, 0));
        fg[0] = true;
        st.erase(0);

        while (!q.empty()) {
            auto [idx, step] = q.front();
            q.pop();
            fg[idx] = true;
            st.erase(idx);
            if (idx == n - 1) return step;

            if (idx != 0 && !fg[idx - 1]) {
                fg[idx - 1] = true;
                st.erase(idx - 1);
                q.push(make_pair(idx - 1, step + 1));
            }
            if (q.size() > 0 && q.back().first == n - 1) return q.back().second;
            if (idx != n - 1 && !fg[idx + 1]) {
                fg[idx + 1] = true;
                st.erase(idx + 1);
                q.push(make_pair(idx + 1, step + 1));
            }
            if (q.size() > 0 && q.back().first == n - 1) return q.back().second;

            if (pt.isP(ns[idx])) {
                //if (pt.isP(ns[idx])) {
                vector<int> rm;
                for (auto i: st) {
                    if (ns[i] % ns[idx] == 0) {
                        fg[i] = true;
                        rm.push_back(i);
                        q.push(make_pair(i, step + 1));
                        if (q.size() > 0 && q.back().first == n - 1) return q.back().second;
                    }
                }
                for (auto i: rm) st.insert(i);
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    _print(s.minJumps({1, 2, 4, 6}));
    _print(s.minJumps({2, 3, 4, 7, 9}));
    _print(s.minJumps({4, 6, 5, 8}));
    _print(s.minJumps({54, 230, 217, 37, 106, 90, 255, 44, 34, 237, 223, 174, 81, 60, 169, 97, 75, (int) 1e6}));
}
