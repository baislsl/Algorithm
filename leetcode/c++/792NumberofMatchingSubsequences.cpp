/**
 * Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input:
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].

 */

#include "leetcode.h"


class Solution {

private:
	int dps(string s, string tar) {
		vector<vector<int>> dp(s.size() + 1, vector<int>(tar.size() + 1, 0));
		for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;
		for (int i = 1; i <= tar.size(); i++) {
			for (int k = 1; k <= s.size(); k++) {
				dp[k][i] = dp[k - 1][i];

				if (s[k - 1] == tar[i - 1]) {
					dp[k][i] += dp[k - 1][i - 1];
				}
			}
		}

		return dp[s.size()][tar.size()];


	}

public:
	int numMatchingSubseq(string S, vector<string> &words) {
		vector<int> ind(S.size(), S.size());
		vector<int> table(1000, S.size());

		for (int i = S.size() - 1; i >= 0; i--) {
			ind[i] = table[S[i]];
			table[S[i]] = i;
		}


		int ans = 0;
		int i = -1;
		for (auto s : words) {
			i = -1;
			int cur = -1;
			for (char cc : s) {
				i = table[cc];
				while (i < cur && i < S.size()) {
					i = ind[i];
				}
				if (i >= S.size()) break;
				cur = i + 1;
			}
			if (i < S.size()) ans += 1;
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<string> w{"a", "bb", "acd", "ace"};
	cout << s.numMatchingSubseq("abcde", w);
}






