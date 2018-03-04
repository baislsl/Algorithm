/**
 * A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true
Note:

board is a length-3 array of strings, where each string board[i] has length 3.
Each board[i][j] is a character in the set {" ", "X", "O"}.
 */

#include "leetcode.h"

class Solution {

private:
	bool mask(char c1, char c2, char c3, char cc) {
		return c1 == cc && c2 == cc && c3 == cc;
	}

public:
	bool win(vector<string> &b, char cc) {
		char data[][3] = {
				{b[0][0], b[0][1], b[0][2]},
				{b[2][0], b[2][1], b[2][2]},
				{b[0][0], b[1][0], b[2][0]},
				{b[0][2], b[1][2], b[2][2]},
				{b[0][0], b[1][1], b[2][2]},
				{b[2][0], b[1][1], b[0][2]}
		};

		for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {

			if (mask(data[i][0], data[i][1], data[i][2], cc)) return true;


		}

		return false;


	}


	bool validTicTacToe(vector<string> &board) {
		int cx, co;
		cx = co = 0;
		for (auto s : board) {
			for (char cc : s) {
				if (cc == 'O') co++;
				if (cc == 'X') cx++;
			}
		}
		if (cx == co) {
			if (cx == 0) return true;
			for (auto &s : board) {
				for (char &cc : s) {
					if (cc == 'O') {
						cc = ' ';
						if (!win(board, 'X') && !win(board, 'O')) return true;
						cc = 'O';
					}
				}
			}

		} else if (cx == co + 1) {
			for (auto &s : board) {
				for (char &cc : s) {
					if (cc == 'X') {
						cc = ' ';
						if (!win(board, 'X') && !win(board, 'O')) return true;
						cc = 'X';
					}
				}
			}


		}

		return false;


	}
};


int main() {
	vector<string> d{"XOX", " X ", "   "};
	vector<string> d2{"O  ", "   ", "   "};
	vector<string> d3{"XXX", "   ", "OOO"};
	vector<string> d4{"XOX", "O O", "XOX"};

	Solution s;

	cout << s.validTicTacToe(d) << endl;
	cout << s.validTicTacToe(d2);
	cout << s.validTicTacToe(d3);
	cout << s.validTicTacToe(d4);

}











