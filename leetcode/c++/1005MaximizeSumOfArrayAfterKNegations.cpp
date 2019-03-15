//
// Created by 白升利 on 2019-03-15.
//

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int ans = 0;
        auto &a = A;
        int zeroInd = -1, zero = 0;

        for(int i = 0; i < a.size(); i ++) {
            ans += a[i];
            if (zeroInd == -1 || abs(zero) > abs(a[i])) {
                zeroInd = i;
                zero = a[i];
            }
        }
        sort(A.begin(), A.end());
        int i = 0;
        for(i = 0; i < K && a[i] < 0; i ++) {
            ans -= 2 * a[i];
        }
        if (i >= K) {
            return ans;
        }

        int left = K - i;
        left %= 2;
        if (left == 1) {
            ans -= 2 * abs((zero));
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> d1{{3, -1, 0, 2}};
    cout << s.largestSumAfterKNegations(d1, 1) << endl;


    vector<int> d2{{2, -3, -1, 5, -4}};
    cout << s.largestSumAfterKNegations(d2, 2) << endl;

}




