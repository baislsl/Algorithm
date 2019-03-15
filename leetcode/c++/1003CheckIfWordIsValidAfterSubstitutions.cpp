#include <string>
#include <iostream>


using namespace std;


class Solution {
public:
    bool isValid(string S) {
        auto &s = S;
        const static string abc = "abc";

        for(int i = 0; i < s.size(); ) {
            if(s.substr(i, 3) == abc) {
                s = s.substr(0, i) + s.substr(i + 3, std::string::npos);
                i = max(0, i - 3);
            } else {
                i ++;
            }
        }
        return s.empty();
    }
};

int main() {
    Solution s;
    cout << s.isValid("aabcbc") << endl;
    cout << s.isValid("abcabcababcc") << endl;
    cout << s.isValid("abccba") << endl;
    cout << s.isValid("cababc") << endl;
}