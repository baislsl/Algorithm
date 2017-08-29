#include <bits/stdc++.h>

using namespace std;

/**
Find the kth largest element in an unsorted array. Note that it is the
 kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

 */


class Solution {
private:
    static int findMid(const vector<int> &nums) {
        if (nums.size() >= 3) {
            auto i = nums.begin();
            int a = *i++, b = *i++, c = *i++;

            if (b < c) std::swap<int>(b, c);
            if (a < b) std::swap<int>(a, b);

            return b;
        } else {
            if (nums.size() == 1) return nums[0];
            else return std::max<int>(nums[0], nums[1]);
        }

    }

public:
    static int findKthLargest(vector<int> &nums, int k) {


        //int key = findMid(nums);
        int key = nums[rand()%nums.size()];
        if (nums.size() == 1) return key;
        if (nums.size() == 2) {
            if (k == 1) return std::max<int>(nums[0], nums[1]);
            else return std::min<int>(nums[1], nums[0]);
        }
        bool flag = false;
        vector<int> l, r;
        for (int a : nums) {
            if(a != key) flag = true;
            if (a > key) l.push_back(a);
            else r.push_back(a);
        }
        if(!flag)
            return nums[0];
        if (l.size() < k) return findKthLargest(r, k - static_cast<int>(l.size()));
        else return findKthLargest(l, k);


    }
};

int main() {
    vector<int> a{3,2,3,1,2,4,5,5,6};
    auto s = new Solution;
    cout << s->findKthLargest(a, 9);
}










