/**
 * Given an array of n positive integers and a positive integer s,
 * find the minimal length of a contiguous subarray of which the sum ≥ s.
 * If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
 */


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int> &nums) {
		int cur = -1, n = nums.size();
		int begin = 0;
		int step = INT_MAX;
		int sum = 0;
		while (cur < n) {
			if (sum >= s) {
				step = min(step, cur - begin + 1);
				sum -= nums[begin];
				begin++;
			} else {
				cur++;
				if(cur < nums.size())
					sum += nums[cur];

			}


		}

		return step == INT_MAX ? 0 : step;


	}
};

int main() {
	vector<int> data{2, 3, 1, 2, 3, 4};
	int s = 7;
	Solution solution;
	cout << solution.minSubArrayLen(s, data) << endl;
}





