
/**
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
 * for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify
 * repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings)
 that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	vector<size_t> fineRepeatImpl(const string &s, int length) {
		auto n = s.length();
		vector<size_t> ans(n);
		if (length == 1) {
			vector<size_t> last(256, n);
			for (int i = s.length() - 1; i >= 0; i--) {
				ans[i] = last[s[i]];
				last[s[i]] = i;
			}
		} else {
			auto vec = fineRepeatImpl(s, length - 1);
			for (size_t i = 0; i < s.length(); i++) {
				size_t cur = vec[i];
				while (cur != n) {
					if (cur + length - 1 < s.length()
						&& s[cur + length - 1] == s[i + length - 1]) {
						break;
					}
					cur = vec[cur];
				}
				ans[i] = cur;
			}
		}

		return ans;
	}

public:
	vector<string> findRepeatedDnaSequences(string s) {
		auto index = fineRepeatImpl(s, 10);
		vector<string> ans;
		vector<bool> trace(s.length(), false);
		for (size_t i = 0; i < s.length(); i++) {

			if (index[i] != s.length() && !trace[i]) {
				ans.push_back(s.substr(i, 10));

				size_t cur = index[i];
				while (cur != s.length()) {
					trace[cur] = true;
					cur = index[cur];
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	auto d1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	auto d2 = "AAAAAAAAAAAA";
	for (auto ss : s.findRepeatedDnaSequences(d2)) {
		cout << ss << endl;
	}
}






