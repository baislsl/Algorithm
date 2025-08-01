//
// Created by baislsl on 2025/7/13.
//

#include "common.hpp"

class Solution {
public:
    using ll = long long;

    char processStr(string s, long long k) {
        ll cnt = 0;
        for (auto cc: s) {
            switch (cc) {
                case '#':
                    cnt *= 2;
                    break;
                case '*':
                    cnt = max(0LL, cnt - 1);
                    break;
                case '%':
                    break;
                default:
                    cnt += 1;
            }
        }
        if (k >= cnt) {
            return '.';
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            char cc = s[i];
            if (cc == '*') {
                cnt += 1;
            } else if (cc == '#') {
                if (k >= cnt / 2) k -= cnt / 2;
                cnt /= 2;
            } else if (cc == '%') {
                k = cnt - k - 1;
            } else {
                if (k == cnt - 1) {
                    return cc;
                }
                cnt--;
            }
            _print(k, cnt, i, s[i]);
        }

        return '.';
    }
};

int main() {
    Solution s;
    _print(s.processStr("abcd%*#", 4));
    _print(s.processStr("a#b%*", 1));
    _print(s.processStr("cd%#*#", 3));
    _print(s.processStr("z*#", 0));
}

