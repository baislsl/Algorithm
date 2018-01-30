/**
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int candy(vector<int> &ratings) {
		vector<int> cand(ratings.size(), 1);
		int n = ratings.size();

		for (int i = 0; i < n; i++) {
			if ((i - 1 < 0 || ratings[i] <= ratings[i - 1])
				&& (i + 1 >= n || ratings[i] <= ratings[i + 1])) {
				int j = i;
				// left
				while (i - 1 >= 0 && ratings[i] < ratings[i - 1]) {
					cand[i - 1] = max(cand[i - 1], cand[i] + 1);
					i--;
				}
				i = j;
				//right
				while (i + 1 < n && ratings[i] < ratings[i + 1]) {
					cand[i + 1] = max(cand[i + 1], cand[i] + 1);
					i++;
				}
				i = j;
			}

		}
		int ans = 0;
		for (auto i : cand) {
			ans += i;
		}
		return ans;

	}

};


int main() {
	Solution s;
	vector<int> rat2{2, 1};
	cout << s.candy(rat2) << endl;

	//					2  1  2  3  1   9
	vector<int> ratings{2, 0, 4, 7, 6};
	cout << s.candy(ratings) << endl;


}

