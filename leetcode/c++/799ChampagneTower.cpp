#include "leetcode.h"

class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass) {
		double p = poured;

		vector<vector<double>> data(query_row + 2, vector<double>(query_row + 3, 0));


		data[0][0] = poured;
		for (int i = 0; i <= query_row; i++) {
			for (int j = 0; j <= i; j++) {
				if (data[i][j] > 1.0) {
					double inc = (data[i][j] - 1.0) / 2;
					data[i + 1][j] += inc;
					data[i + 1][j + 1] += inc;
				}
			}
		}

		return data[query_row][query_glass] > 1.0 ? 1.0 : data[query_row][query_glass];


	}
};


int main() {
	Solution s;
	cout << s.champagneTower(6, 2, 0) << endl;
	cout << s.champagneTower(4, 2, 0) << endl;
	cout << s.champagneTower(1, 1, 1) << endl;
	cout << s.champagneTower(2, 1, 1) << endl;

}
