/**
Given a binary tree with n nodes, your task is to check if it's possible to
 partition the tree to two trees which have the equal sum of values after
 removing exactly one edge on the original tree.

Example 1:
Input:
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation:
    5
   /
  10

Sum: 15

   10
  /  \
 2    3

Sum: 15
Example 2:
Input:
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after
 removing exactly one edge on the tree.
Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000
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

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int sum;
    bool result = false;

    int getSum(TreeNode *node) {
        if (node == nullptr) return 0;
        return node->val + getSum(node->left) + getSum(node->right);
    }

    int travel(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = travel(root->left);
        int right = travel(root->right);
        if (left == sum / 2 && root->left) result = true;
        if (right == sum / 2 && root->right) result = true;

        // if (left == sum / 2 || right == sum / 2) result = true;

        return left + right + root->val;

    }

public:
    bool checkEqualTree(TreeNode *root) {
        sum = getSum(root);
        if (sum % 2 != 0) return false;
        travel(root);
        return result;
    }
};














