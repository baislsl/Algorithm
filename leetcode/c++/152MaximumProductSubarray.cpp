/**
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
 */

#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
	// no zeros
	int maxImpl(const vector<int> &nums, int begin, int end) {
		if (nums.empty() || begin >= end) return 0;
		if (end - begin == 1)
			return nums[begin];
		int cur = 1;
		int ans = 1;
		for (int i = begin; i < end; i++) {
			cur *= nums[i] > 0 ? 1 : -1;
			ans *= nums[i];
		}
		if (cur < 0) {
			int left, right;
			left = begin;
			right = end - 1;
			int leftp = 1, rightp = 1;
			while (left < end) {
				leftp *= nums[left];
				if (leftp < 0) break;
				left++;
			}
			while (right >= begin) {
				rightp *= nums[right];
				if (rightp < 0) break;
				right--;
			}
			return ans / (max(leftp, rightp));
		} else {
			return ans;
		}


	}

public:
	int maxProduct(const vector<int> &nums) {
		if(nums.size() == 1)
			return nums[0];
		vector<int> section;
		section.push_back(-1);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				section.push_back(i);
			}
		}

		section.push_back(nums.size());

		int ans = 0;
		for(int i = 0; i < section.size() - 1; i ++){
			ans = max(ans, maxImpl(nums, section[i] + 1, section[i + 1]));
		}
		return ans;
	}
};

int main(){
	Solution s;
	vector<int> t1{-2, 0, -1};;
	cout << s.maxProduct(t1) << endl;

	vector<int> t2{2, 3, -2, 4, 0, 9, 8, -3, -2, 5 };
	cout << s.maxProduct(t2) << endl;


}