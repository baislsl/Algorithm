/**
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original
 string by deleting some (can be none) of the characters without disturbing
 the relative positions of the remaining characters. (ie, "ACE" is a subsequence
 of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
 */

#include <bits/stdc++.h>

#define DEBUG
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {

		vector<bool> tb(1000, false);
		for (auto c : t) {
			tb[c] = true;
		}
		string ns;
		for (auto c : s) {
			if(tb[c])
				ns += c;
		}
		s = ns;


		vector<vector<int>> dp;
		for (int i = 0; i <= s.size(); i++) {
			vector<int> v(t.size() + 1, 0);
			dp.emplace_back(v);
		}

		for (int i = 0; i <= s.size(); i++) {
			dp[i][0] = 1;
		}

		for (int i = 1; i <= t.size(); i++) {
			for (int j = 1; j <= s.size(); j++) {
				dp[j][i] = dp[j - 1][i];
				if (s[j - 1] == t[i - 1])
					dp[j][i] += dp[j - 1][i - 1];
			}
		}
#ifdef DEBUG
		for (int i = 0; i < t.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				cout << dp[j][i] << " ";
			}
			cout << endl;
		}

#endif
		return dp[s.size()][t.size()];
	}
};

int main() {
	Solution s;
	cout << s.numDistinct("rabbbit", "rabbit") << endl;
	cout << s.numDistinct("abcdef", "ace") << endl;
	cout << s.numDistinct("abcdef", "aec") << endl;

}