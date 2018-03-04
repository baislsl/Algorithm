/**
 * We are given an array A of positive integers, and two positive integers L and R (L <= R).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.

Example :
Input:
A = [2, 1, 4, 3]
L = 2
R = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Note:

L, R  and A[i] will be an integer in the range [0, 10^9].
The length of A will be in the range of [1, 50000].
 */

#include "leetcode.h"


class Solution {

private:
	int impl(vector<int> &a, int l, int r, int begin, int end) {
		if (begin >= end) return 0;

		int size = end - begin;
		vector<int> gap;

		int cur = begin;
		for (int i = begin; i < end; i++) {
			if (a[i] >= l) {
				if (i - cur > 0)
					gap.push_back(i - cur);
				cur = i + 1;
			}
		}
		if (end - cur >= 1) gap.push_back(end - cur);

		int count = (size * (size + 1)) / 2;
		for (int i : gap) {
			count -= i * (i + 1) / 2;
		}
		return count;
	}

public:
	int numSubarrayBoundedMax(vector<int> &A, int L, int R) {
		int begin = 0;
		int end;
		int count = 0;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] > R) {
				count += impl(A, L, R, begin, i);
				begin = i + 1;
			}
		}
		count += impl(A, L, R, begin, A.size());

		return count;
	}
};

int main() {
	vector<int> d{73, 55, 36, 5, 55, 14, 9, 7, 72, 52
	};
	vector<int> d2{2, 1, 4, 3};
	Solution s;
	cout << s.numSubarrayBoundedMax(d2, 2, 3);
}












