/**
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {

private:
	void travel(int i, int j, const vector<vector<char>> &board,
				vector<vector<bool >> &flag) {
		if(flag[i][j] || board[i][j] == 'X')
			return ;
		flag[i][j] = true;
		static std::array<std::array<int, 2>, 4> dir{{{0, -1}, {0, 1}, {1, 0}, {-1, 0}}};
		for (auto &d : dir) {
			int ni = i + d[0], nj = j + d[1];
			if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
				travel(ni, nj, board, flag);
			}
		}
	}

public:
	void solve(vector<vector<char>> &board) {
		if (board.empty() || board[0].empty())
			return;
		vector<vector<bool >> flag(board.size(), vector<bool>(board[0].size(), false));

		int i = 0;
		for (int j = 0; j < board[0].size(); j++) {
			if (flag[i][j] || board[i][j] == 'X') continue;
			travel(i, j, board, flag);
		}
		i = board.size() - 1;
		for (int j = 0; j < board[0].size(); j++) {
			if (flag[i][j] || board[i][j] == 'X') continue;
			travel(i, j, board, flag);
		}

		int j = 0;
		for(int i = 0; i < board.size();i++){
			if (flag[i][j] || board[i][j] == 'X') continue;
			travel(i, j, board, flag);
		}
		j = board[0].size() - 1;
		for(int i = 0; i < board.size();i++){
			if (flag[i][j] || board[i][j] == 'X') continue;
			travel(i, j, board, flag);
		}

		for(i = 0; i < board.size(); i++){
			for(int j = 0; j < board[0].size();j++){
				if (!flag[i][j]) board[i][j] = 'X';
			}
		}
	}
};

int main(){
	char x = 'X', o = 'O';
	vector<vector<char>> board{
			{x, o, x, o, x, o},
			{o, x, o, x, o, x},
			{x, o, x, o, x, o},
			{o, x, o, x, o, x},
	};
	Solution s;
	s.solve(board);
	for(auto &vs : board){
		for(auto cc : vs){
			cout << cc << " ";
		}
		cout << endl;
	}
}
