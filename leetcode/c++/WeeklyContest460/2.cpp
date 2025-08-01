#include "common.hpp"

using namespace std;

class Solution {
public:
    long long impl(string s, bool fg) {
        int n = s.size();
        vector<long long> l(n, 0), t(n, 0);
        int lc = 0;
        for (int i = 0; i + 1 < s.size(); ++i) {
            if (s[i] == 'L') lc++;
            l[i + 1] = lc;
        }
        int tc = 0;
        for (int j = n - 1; j >= 1; --j) {
            if (s[j] == 'T') tc++;
            t[j - 1] = tc;
        }

        long long ans = 0;
        long long inc = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'C') {
                ans += l[i] * t[i];
            }
            inc = max<long long>(inc, l[i] * t[i]);
        }
        if (fg) ans += inc;
        return ans;
    }

    long long numOfSubsequences(string ns) {
        string s = "M";
        for (auto cc : ns) {
            s += cc;
            s += 'M';
        }

        auto v1 = impl(s, true);
        auto v2 = impl("L" + s, false);
        auto v3 = impl(s + "T", false);
        return max(v1, max(v2, v3));
    }
};

int main() {
    Solution s;
    _print(s.numOfSubsequences(string("LMCT")));
    _print(s.numOfSubsequences(string("LCCT")));
    _print(s.numOfSubsequences(string("LT")));
    _print(s.numOfSubsequences(string("L")));
}
