/**
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
		auto s1 = nums1.size(), s2 = nums2.size();
		if ((s1 + s2) % 2 == 0) {
			int r1 = findK((s1 + s2) / 2, nums1, nums2, 0, 0, s1, s2);
			int r2 = findK((s1 + s2) / 2 - 1, nums1, nums2, 0, 0, s1, s2);
			return (r1 + r2) / 2.0;
		} else {
			return findK((s1 + s2) / 2, nums1, nums2, 0, 0, s1, s2);
		}
	}

private:
	int findK(int k, vector<int> &nums1, vector<int> &nums2, int b1, int b2, int e1, int e2) {
		if (b1 == e1) {
			return nums2[b2 + k];
		} else if (b2 == e2) {
			return nums1[b1 + k];
		}
		if (k == 0)
			return std::min(nums1[b1], nums2[b2]);
		else if (k == 1) {
			if (nums1[b1] < nums2[b2]) {
				if (b1 + 1 < e1) return std::min(nums1[b1 + 1], nums2[b2]);
				else return nums2[b2];
			} else {
				if (b2 + 1 < e2) return std::min(nums1[b1], nums2[b2 + 1]);
				else return nums1[b1];
			}
		}

		int d = k / 2 - 1;
		int d1 = std::min(d, e1 - b1 - 1), d2 = std::min(d, e2 - b2 - 1);
		if (nums1[b1 + d1] < nums2[b2 + d2]) {
			return findK(k - d1 - 1, nums1, nums2, b1 + d1 + 1, b2, e1, e2);
		} else {
			return findK(k - d2 - 1, nums1, nums2, b1, b2 + d2 + 1, e1, e2);
		}


	}
};

int main() {
	Solution s;

	vector<int>n8{{1}};
	vector<int>n7{{2, 3, 4}};
	cout << s.findMedianSortedArrays(n7, n8) << endl;

	vector<int> n1{{1, 3}};
	vector<int> n2{{2,}};


	cout << s.findMedianSortedArrays(n1, n2) << endl;

	vector<int> n3{{1, 2}};
	vector<int> n4{{3, 4}};
	cout << s.findMedianSortedArrays(n3, n4) << endl;

	vector<int> n5{{1, 4, 5, 7, 8, 9}};
	vector<int> n6{{0, 2, 3, 6, 10}};
	cout << s.findMedianSortedArrays(n5, n6) << endl;


}
