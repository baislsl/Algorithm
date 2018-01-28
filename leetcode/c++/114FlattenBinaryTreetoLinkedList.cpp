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

	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};


class Solution {
private:
	void flattenImp(TreeNode *root, TreeNode *&head, TreeNode *&tail) {
		if (root == nullptr) {
			head = tail = nullptr;
			return;
		}

		TreeNode *leftHead, *rightHead, *leftTail, *rightTail;
		flattenImp(root->left, leftHead, leftTail);
		flattenImp(root->right, rightHead, rightTail);
		TreeNode * temp = root->right;
		if (root->left != nullptr) {
			root->right = leftHead;
		} else {
			leftTail = root;
		}
		root->left = nullptr;

		if (temp != nullptr) {
			leftTail->right = rightHead;
			head = root;
			tail = rightTail;
		} else {
			head = root;
			tail = leftTail;
		}
		tail->right = tail->left = nullptr;
		return;;
	}

public:
	void flatten(TreeNode *root) {
		TreeNode *head, *tail;
		flattenImp(root, head, tail);
	}
};

int main() {
	TreeNode a1(0);
	TreeNode a2(2);
	TreeNode a3(3);
	a1.left = &a2;
	Solution s;
	s.flatten(&a1);
}