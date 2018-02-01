/**
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],

   1
    \
     2
    /
   3


return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?


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
	vector<int> postorderTraversal(TreeNode *root) {
		std::stack<TreeNode *> stack1;
		std::stack<TreeNode *> stack2;

		stack1.push(root);
		while (!stack1.empty()) {
			auto node = stack1.top();
			stack1.pop();
			if(node == nullptr) continue;
			stack1.push(node->left);
			stack1.push(node->right);
			stack2.push(node);
		}


		vector<int> ans;
		size_t cur = stack2.size() - 1;
		while (!stack2.empty()){
			ans.push_back(stack2.top()->val);
			stack2.pop();
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
	auto ans = s.postorderTraversal(&nodes[0]);
	for(auto i : ans)
		cout << i << " ";

}
