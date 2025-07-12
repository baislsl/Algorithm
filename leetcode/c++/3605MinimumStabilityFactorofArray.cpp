//
// Created by baislsl on 2025/7/7.
//
#include "common.hpp"
#include "SparseTable.hpp"

class Solution {
public:
    int minStable(const vector<int> &nums, int maxC) {
        int n = nums.size();
        SparseTable<int> st(nums, [](int a, int b) {
            return std::gcd(a, b);
        });

        auto canR = [&](int tg) {
            int i = 0, j = 0;
            int count = 0;
            while (i < n) {
                while (j <= i) {
                    int gd = st.query(j, i);
                    if (gd == 1) {
                        j++;
                    } else {
                        if (i - j + 1 > tg) {
                            if (++count > maxC) {
                                return false;
                            }
                            j = i + 1;
                        }
                        break;
                    }
                }
                i++;
            }
            return true;
        };

        int lf = 1, ri = n;
        int ans = 0;
        int ct = 0;
        for (auto i: nums) if (i != 1) ct++;
        if (ct <= maxC) return 0;

        while (lf <= ri) {
            int mid = lf + (ri - lf) / 2;
            if (canR(mid)) {
                ans = mid;
                ri = mid - 1;
            } else {
                lf = mid + 1;
            }
        }
        return ans;
    }
};


int main() {
    int n = 100;
    vector<int> log2s(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        log2s[i] = log2s[i / 2] + 1;
        //cout << i << " " << log2s[i] << " " << static_cast<int>(log2(i)) << endl;
        assert(log2s[i] == static_cast<int>(log2(i)));
    }

    Solution s;
    _print(s.minStable({25, 12, 18}, 0));
    _print(s.minStable({8, 5}, 0));
    _print(s.minStable({2, 6, 9, 6}, 1));
    _print(s.minStable({3, 5, 10}, 1));
    _print(s.minStable({2, 6, 8}, 2));
}
