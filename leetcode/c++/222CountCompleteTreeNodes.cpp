/**
 * Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last,
 is completely filled, and all nodes in the last level are as far left as possible.
 It can have between 1 and 2h nodes inclusive at the last level h.
 *
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
	TreeNode *left, *right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
	int countNodesImpl(TreeNode *root, int &h) {
		if (root == nullptr) {
			h = 0;
			return 0;
		}
		if (root->left == nullptr) {
			h = 1;
			return 1;
		} else {
			int n = countNodesImpl(root->left, h);
			if (n < (1 << h) - 1) {
				h++;
				return 1 + n + (1 << (h - 2)) - 1;
			} else {
				int temp;
				int ans = 1 + n + countNodesImpl(root->right, temp);
				h++;
				return ans;
			}
		};


	}

public:
	int countNodes(TreeNode *root) {
		int h;
		return countNodesImpl(root, h);

	}
};


int main() {
	vector<TreeNode> data{1,2 , 3, 4};
	data[0].left = &data[1];
	data[1].left = &data[2];
	data[0].right = &data[3];

	Solution s;
	cout << s.countNodes(&data[0]);
}

