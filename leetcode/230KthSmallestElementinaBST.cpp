/**
 *
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
 */


#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	TreeNode *kthImpl(TreeNode *root, int k, int &counter) {
		if (root == nullptr) {
			counter = 0;
			return root;
		}

		TreeNode *node = kthImpl(root->left, k, counter);
		if (node != nullptr) return node;
		++counter;
		if (counter == k) {
			return root;
		}

		int cnt;
		node = kthImpl(root->right, k - counter, cnt);
		counter += cnt;
		return node;
	}

public:
	int kthSmallest(TreeNode *root, int k) {
		int counter = 0;
		return kthImpl(root, k, counter)->val;
	}
};

int main() {
	vector<TreeNode> nodes{0, 1, 2, 3, 4, 5};
	nodes[3].left = &nodes[1];
	nodes[3].right = &nodes[5];

	nodes[5].left = &nodes[4];
	nodes[1].left = &nodes[0];
	nodes[1].right = &nodes[2];


	Solution s;
	for (int i = 0; i < nodes.size(); i++) {
		cout << s.kthSmallest(&nodes[3], i + 1) << endl;


	}


}