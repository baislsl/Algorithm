/**
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of
 nodes from some starting node to any node in the tree along
 the parent-child connections. The path must contain at least
 one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	// return max left and right
	int maxImp(TreeNode *root, int &ans) {
		if (root == nullptr) return 0;
		int left = maxImp(root->left, ans), right = maxImp(root->right, ans);
		if(left < 0) left = 0;
		if(right < 0) right = 0;
		ans = std::max(ans, left + right + root->val);
		return std::max(left, right) + root->val;
	}

public:
	int maxPathSum(TreeNode *root) {
		int ans = INT_MIN;
		maxImp(root, ans);
		return ans;
	}
};

int main() {
	vector<TreeNode> ts{0, 1, 2, 3};
	ts[0].left = &ts[1];
	ts[0].right = &ts[2];
	ts[1].right = &ts[3];
	Solution s;
	cout << s.maxPathSum(&ts[0]);
}