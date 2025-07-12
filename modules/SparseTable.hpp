//
// Created by baislsl on 2025/7/7.
//

#ifndef SPARSETABLE_HPP
#define SPARSETABLE_HPP


#include <bits/stdc++.h>
using namespace std;

template<typename T>
class SparseTable {
private:
    vector<vector<T> > st;
    vector<int> log2s;
    function<T(const T &, const T &)> combine;
    int n;

public:
    SparseTable(const vector<T> &nums, function<T(const T &, const T &)> combine)
        : combine(combine), n(nums.size()) {
        int maxLog = log2(n) + 1;
        st.assign(n, vector<T>(maxLog));
        log2s.assign(n + 1, 0);

        for (int i = 2; i <= n; ++i) log2s[i] = log2s[i / 2] + 1;

        for (int i = 0; i < n; ++i) st[i][0] = nums[i];

        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                st[i][j] = this->combine(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        int k = log2s[r - l + 1];
        return combine(st[l][k], st[r - (1 << k) + 1][k]);
    }
};


#endif //SPARSETABLE_HPP
