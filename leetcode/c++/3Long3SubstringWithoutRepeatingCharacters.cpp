/**
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer
 must be a substring, "pwke" is a subsequence and not a substring.
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int size = s.size();
		vector<int> last(s.size());
		vector<int> word(256, size);

		for (int i = s.size() - 1; i >= 0; i--) {
			last[i] = word[s[i]];
			word[s[i]] = i;
		}
		if(s.empty())
			return 0;
		int ans = 1;
		for (int i = s.size() - 2; i >= 0; i--) {
			last[i] = std::min(last[i + 1], last[i]);
			ans = std::max(ans, last[i] - i);
		}

		return ans;


	}
};

int main(){
	Solution s;
	cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
	cout << s.lengthOfLongestSubstring("bbbbb") << endl;
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
}