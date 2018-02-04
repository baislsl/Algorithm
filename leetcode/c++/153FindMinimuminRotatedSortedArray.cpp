/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	int findImpl(const vector<int> &nums, int begin, int end) {
		if(end - begin <= 3) {
			int ans = INT_MAX;
			for(int i = begin; i < end; i ++){
				ans = std::min(ans, nums[i]);
			}
			return ans;
		}
		int mid = (begin + end) / 2;
		return nums[mid] > nums[end - 1] ? findImpl(nums, mid, end) : findImpl(nums, begin, mid + 1);
	}


public:
	int findMin(vector<int> &nums) {
		return findImpl(nums, 0, nums.size());
	}
};


int main(){
	Solution s;
	vector<int> d1{4, 5, 6, 7, 0, 1, 2};


	cout << s.findMin(d1) << endl;


}
