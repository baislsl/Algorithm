/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

Seen this question in a real interview before?  YesNo

 */


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int minCut(string s) {
		vector<vector<bool>> match(s.length(), vector<bool>(s.length(), false));
		for (int i = 0; i < s.length(); i++)
			match[i][i] = true;


		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j <= i; j++) {
				if (s[i] == s[j] && (j + 1 >= i - 1 || match[j + 1][i - 1])) {
					match[i][j] = match[j][i] = true;
				}
			}
		}


		int dp[s.length() + 1];
		dp[0] = 0;


		for (int i = 0; i < s.length(); i++) {
			dp[i + 1] = dp[i] + 1;
			for (int j = 0; j <= i; j++) {
				if (match[i][j]) {
					dp[i + 1] = min(dp[i + 1], dp[j] + 1);
				}
			}
		}

		return dp[s.length()] - 1;


	}
};


int main() {
	Solution s;
	cout << s.minCut("aad");


}