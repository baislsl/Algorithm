/**
 * Implement an iterator over a binary search tree (BST).
 * Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and
 uses O(h) memory, where h is the height of the tree.


 */


#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left, *right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
	std::stack<TreeNode *> ss;
	TreeNode *cur;

public:
	BSTIterator(TreeNode *root) {
		if (root == nullptr) {
			cur = nullptr;
			return;
		}
		while (root->left != nullptr) {
			ss.push(root);
			root = root->left;
		}
		cur = root;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return cur != nullptr;
	}

	/** @return the next smallest number */
	int next() {
		int ans = cur->val;
		if (cur->right != nullptr) {
			cur = cur->right;
			while (cur->left != nullptr) {
				ss.push(cur);
				cur = cur->left;
			}
		} else {
			if (!ss.empty()) {
				cur = ss.top();
				ss.pop();
			} else {
				cur = nullptr;
			}
		}
		return ans;
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
	std::vector<TreeNode> ds{0, 1, 2, 3, 4, 5};
	ds[3].left = &ds[1];
	ds[3].right = &ds[4];
	ds[1].right = &ds[2];
	ds[1].left = &ds[0];
	ds[4].right = &ds[5];


	BSTIterator i = BSTIterator(&ds[3]);
	while (i.hasNext())
		cout << i.next() << " ";




}
