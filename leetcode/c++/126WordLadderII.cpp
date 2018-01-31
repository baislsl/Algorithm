/**
Given two words (beginWord and endWord), and a dictionary's word list,
 find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
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
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
		vector<string> words;
		vector<vector<string>> ans;
		if (beginWord.length() != endWord.length()) return ans;

		for (auto &s : wordList) {
			if (s.length() == beginWord.length()) {
				words.push_back(s);
			}
		}

//		words.push_back(endWord);
		words.push_back(beginWord);

		int endIndex = -1;
		for (int i = 0; i < words.size(); i++) {
			if (words[i] == endWord)
				endIndex = i;
		}
		if (endIndex == -1)
			return ans;

		vector<vector<bool> > mat(words.size(), vector<bool>(words.size(), false));

		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < i; j++) {
				mat[i][j] = mat[j][i] = diff(words[i], words[j]);
			}
		}
#ifdef DEBUG
		for (int i = 0; i < words.size(); i++) cout << words[i] << " ";
		for (int i = 0; i < words.size(); i++) {
			cout << endl;
			for (int j = 0; j < words.size(); j++) {
				cout << mat[i][j] << " ";
			}
		}
#endif
		int n = words.size();

		vector<int> dist(words.size(), INT_MAX);
		vector<bool> flag(words.size(), false);
		vector<vector<int>> pre(n, vector<int>());
		int cur = words.size() - 1;
		dist[cur] = 1;
		int cnt = words.size();
		while (cnt--) {
			flag[cur] = true;
			for (int i = 0; i < words.size(); i++) {
				if (mat[i][cur]) {
					if (dist[cur] + 1 <= dist[i]) {
						if (dist[cur] + 1 == dist[i]) {
							pre[i].push_back(cur);
						} else {
							pre[i].clear();
							pre[i].push_back(cur);
						}
						dist[i] = dist[cur] + 1;
					}
				}
			}


			cur = -1;
			int minDist = 0;
			for (int i = 0; i < n; i++) {
				if (!flag[i] && (cur == -1 || minDist > dist[i])) {
					cur = i;
					minDist = dist[i];
				}
			}

			if (cur == -1) break;

		}

		if (dist[endIndex] == INT_MAX) return ans;

		int beginIndex = words.size() - 1;
		vector<string> collect;
		collect.push_back(endWord);
		travel(ans, beginIndex, endIndex, pre, words, collect, dist, 0, dist[endIndex]);
		return ans;


	}

	void travel(vector<vector<string>> &ans, int target, int cur, vector<vector<int>> &pre, vector<string> words,
				vector<string> &collect, vector<int> dist, int curDist, int totalDist) {
		if (cur == target) {
			vector<string> result;
			for(auto i = collect.crbegin(); i != collect.crend(); ++i){
				result.push_back(*i);
			}
			ans.push_back(result);
			return;
		}
		if (totalDist - curDist == dist[cur]) {
			for(auto next : pre[cur]){
				collect.push_back(words[next]);
				travel(ans, target, next, pre, words, collect, dist, curDist + 1, totalDist);
				collect.resize(collect.size() - 1);
			}
		}


	}
};


int main() {
	Solution s;
	vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
	vector<string> wordList2{"hot", "dot", "dog", "lot", "log"};

	auto a1 = s.findLadders("hit", "cog", wordList);

	for(auto vs : a1){
		cout << endl;
		for(auto s : vs){
			cout << s << " ";
		}

	}


//	cout << s.findLadders("hit", "cog", wordList) << endl;
//	cout << s.findLadders("hit", "cog", wordList2) << endl;
}























