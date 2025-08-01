#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;

class Solution {
    using ll = long long;

public:
    long long maximumMedianSum(vector<int> &ns) {
        std::sort(ns.begin(), ns.end());
        int n = ns.size();
        ll rst = 0;
        for (int i = 0, j = n - 2; i < j; i++, j -= 2) {
            rst += ns[j];
        }
        return rst;
    }
};

int main() {
    Solution s;
    //cout << s.maximumMedianSum({2,1,3,2,1,3}) << endl;
    //cout << s.maximumMedianSum({1,1,10,10,10,1}) << endl;
}
