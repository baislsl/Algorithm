/**
Given an integer n, count the total number of digit 1 appearing
 in all non-negative integers less than or equal to n.
For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 */
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Solution {
private:
    // 0 - pow(10, n)
    static int getlow(int n) {
        return n * static_cast<int>(std::pow(10, n - 1));
    }
public:

    static int countDigitOne(int n) {
        if (n <= 0) return 0;

        int g = static_cast<int>(std::log10(n));
        int high = n / static_cast<int>(std::pow(10, g));
        int tmp = static_cast<int>(std::pow(10, g));
        if (high == 1) return getlow(g) + n - tmp + 1 + countDigitOne(n - tmp);
        // if (high == 2) return getlow(g) + tmp + getlow(g) + countDigitOne(n % tmp);
        // return getlow(g) + tmp + (high - 1) * getlow(g) + countDigitOne(n % tmp);
        return high * getlow(g) + countDigitOne(n % tmp) + tmp;
    }
};


static int count(int n) {
    int result = 0;
    while (n != 0) {
        if (n % 10 == 1) result += 1;
        n /= 10;
    }
    return result;
}

int main() {
    int total = 0;
    for (int i = 0; i < 7; i++) {
        int begin = static_cast<int>(std::pow(10, i));
        int end = static_cast<int>(std::pow(10, i + 1));

        int cc = 0;
        for (int j = begin; j < end; j++) {
            cc += count(j);
        }
        total += cc;

        cout << 0 << "-" << end << " : " << total << endl;
    }

    cout << Solution::countDigitOne(10000) << endl;
    cout << Solution::countDigitOne(13) << endl;
    cout << Solution::countDigitOne(23) << endl;
    cout << Solution::countDigitOne(33) << endl;


}