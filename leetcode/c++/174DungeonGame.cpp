/**
 * The demons had captured the princess (P) and imprisoned her
 * in the bottom-right corner of a dungeon. The dungeon consists
 * of M x N rooms laid out in a 2D grid. Our valiant knight (K) was
 * initially positioned in the top-left room and must fight his way through
 * the dungeon to rescue the princess.
 * The knight has an initial health point represented by a positive integer.
 If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers)
 upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that
 increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move
 only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he
 is able to rescue the princess.

 *
 */

#include <bits/stdc++.h>
#define DEBUG
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>> &dungeon) {
		int n = dungeon.size();
		if (n == 0) return 0;
		int m = dungeon[0].size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
		dp[n][m - 1] = dp[n - 1][m] = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				dp[i][j] = std::min(dp[i + 1][j], dp[i][j + 1]);
				if(dp[i][j] <= dungeon[i][j])
					dp[i][j] = 0;
				else
					dp[i][j] -= dungeon[i][j];
			}
		}
#ifdef DEBUG
		for(int i = 0; i < n;i++){
			for(int j = 0; j < m;j++){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
#endif
		return dp[0][0] + 1;

	}
};


int main(){
	vector<vector<int>> dungeon{
			{-2, -3, 3},
			{-5, -10, 1},
			{10, 30, -5}
	};

	Solution s;
	cout << s.calculateMinimumHP(dungeon) << endl;
}

