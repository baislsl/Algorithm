#include "leetcode.h"

class Solution {
public:
	bool rotateString(string A, string B) {
		string a = A, b = B;


		if (a.size() != b.size()) return false;

		for (int i = 0; i < a.size(); i++) {

			string s = a.substr(i, a.size()- i) + a.substr(0, i);
			if(s == b) return true;


		}

		return false;
	}
};


int main() {
	Solution s;
	cout <<  std::boolalpha << s.rotateString("abcde", "cdeab") << endl;
	cout <<  std::boolalpha << s.rotateString("abcde", "abced") << endl;

}
