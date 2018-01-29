/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<vector<string>>> dp(s.length() + 1);
		if(s.empty())
			return dp[0];
		vector<string> temp;
		dp[0].push_back(temp);


		vector<vector<bool>> match(s.length(), vector<bool>(s.length(), false));
		for (int i = 0; i < s.length(); i++) match[i][i] = true;

		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j <= i; j++) {
				if (s[j] == s[i] && (j + 1 > i - 1 || match[j + 1][i - 1])) {
					for (int k = 0; k < dp[j].size(); k++) {
						vector<string> v(dp[j][k]);
						v.push_back(s.substr(j, i - j + 1));
						dp[i + 1].push_back(v);
					}
					match[j][i] = true;
				}

			}
		}
		return dp[s.length()];
	}
};

void printV(const vector<vector<string>> &data) {
	for (auto &v: data) {
		for (auto &s:v) {
			cout << s << " ";
		}
		cout << endl;
	}
}

int main() {
	Solution s;

	printV(s.partition("aab"));
	printV(s.partition("aabaacbca"));
}