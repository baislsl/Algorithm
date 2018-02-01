/**
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left, *right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:

public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ans;
		std::stack<TreeNode *> stack1;

		stack1.push(root);
		while (!stack1.empty()) {
			auto node = stack1.top();
			stack1.pop();
			if(node == nullptr) continue;
			ans.push_back(node->val);
			stack1.push(node->right);
			stack1.push(node->left);
		}


		return ans;

	}
};

int main(){
	vector<TreeNode> nodes{0, 1, 2, 3};
	nodes[0].left = nullptr;
	nodes[0].right = &nodes[1];
	nodes[1].left = &nodes[2];
	nodes[1].right = &nodes[3];
	Solution s;
	auto ans = s.preorderTraversal(&nodes[0]);
	for(auto i : ans)
		cout << i << " ";

}
