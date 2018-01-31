/**
Given two words (beginWord and endWord), and a dictionary's word list,
 find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings).
 Please reload the code definition to get the latest changes.

 */

#include <bits/stdc++.h>
#define DEBUG
using namespace std;

class Solution {

private:
	bool diff(string s1, string s2) {
		if (s1.length() != s2.length()) return false;

		int cnt = 0;
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i]) cnt++;
			if (cnt >= 2) return false;
		}

		return cnt == 1;
	}

public:
	int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
		vector<string> words;
		if (beginWord.length() != endWord.length()) return 0;

		for (auto &s : wordList) {
			if (s.length() == beginWord.length()) {
				words.push_back(s);
			}
		}

//		words.push_back(endWord);
		words.push_back(beginWord);

		int endIndex = -1;
		for(int i = 0; i < words.size(); i++){
			if(words[i] == endWord)
				endIndex = i;
		}
		if(endIndex == -1)
			return 0;

		vector<vector<bool> > mat(words.size(), vector<bool>(words.size(), false));

		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < i; j++) {
				mat[i][j] = mat[j][i] = diff(words[i], words[j]);
			}
		}
#ifdef DEBUG
		for(int i = 0; i < words.size(); i++) cout << words[i] << " ";
		for(int i = 0;i < words.size(); i++){
			cout << endl;
			for(int j = 0; j < words.size(); j++){
				cout << mat[i][j] << " ";
			}
		}
#endif
		int n = words.size();

		vector<int> dist(words.size(), INT_MAX);
		vector<bool> flag(words.size(), false);
		int cur = words.size() - 1;
		dist[cur] = 1;
		int cnt = words.size();
		while (cnt--) {
			flag[cur] = true;
			for (int i = 0; i < words.size(); i++) {
				if (mat[i][cur])
					dist[i] = min(dist[i], dist[cur] + 1);
			}


			cur = -1;
			int minDist = 0;
			for (int i = 0; i < n; i++) {
				if (!flag[i] && (cur == -1 || minDist > dist[i])) {
					cur = i;
					minDist = dist[i];
				}
			}

			if(cur == -1) break;

		}

		if(dist[endIndex] == INT_MAX) return 0;
		return dist[endIndex];


	}
};


int main() {
	Solution s;
	vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
	vector<string> wordList2{"hot","dot","dog","lot","log"};

	cout << s.ladderLength("hit", "cog", wordList) << endl;
	cout << s.ladderLength("hit", "cog", wordList2) << endl;
}
























