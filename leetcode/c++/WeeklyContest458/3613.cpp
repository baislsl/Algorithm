//
// Created by baislsl on 2025/7/13.
//

#include "common.hpp"

class Solution {
public:
    string processStr(string s) {
        string res = "";
        for (auto cc: s) {
            switch (cc) {
                case '#':
                    res += res;
                    break;
                case '*':
                    if (res.size() > 0) res = res.substr(0, res.size() - 1);
                    break;
                case '%':
                    reverse(res.begin(), res.end());
                    break;
                default:
                    res += cc;

            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << "123" << endl;
}
