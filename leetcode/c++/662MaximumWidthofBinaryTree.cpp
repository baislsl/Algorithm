/**
 * Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input:

           1
         /   \
        3     2
       / \     \
      5   3     9

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input:

          1
         /
        3
       / \
      5   3

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input:

          1
         / \
        3   2
       /
      5

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input:

          1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.


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
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
#define MAXHEIGHT 100000

private:
    int left[MAXHEIGHT], right[MAXHEIGHT];

    void init(){
        for(int i=0;i<MAXHEIGHT;i++){
            left[i] = INT_MAX;
            right[i] = INT_MIN;
        }
    }

    void travel(TreeNode *node, int mid, int height) {
        int ileft, iright;

        if (mid < 0) {
            ileft = 2 * mid;
            iright = 2 * mid + 1;
        } else if (mid > 0) {
            ileft = 2 * mid - 1;
            iright = 2 * mid;
        } else if (mid == 0) {
            ileft = -1;
            iright = 1;
        }

        if (node == nullptr) return;
        if (node->left != nullptr) {
            right[height + 1] = std::max(right[height + 1], ileft);
            left[height + 1] = std::min(left[height + 1], ileft);
            travel(node->left, ileft, height + 1);
        }
        if (node->right != nullptr) {
            right[height + 1] = std::max(right[height + 1], iright);
            left[height + 1] = std::min(left[height + 1], iright);
            travel(node->right, iright, height + 1);
        }


    }

public:

    int widthOfBinaryTree(TreeNode *root) {
        init();
        if (root == nullptr) return 0;
        travel(root, 0, 0);

        int ret = 1;

        for (int i = 0; i < MAXHEIGHT; i++) {
            if(left[i] == INT_MAX || right[i] == INT_MIN) continue;

            int k = right[i] - left[i];
            if(right[i] < 0 && left[i] < 0) k += 1;
            if(right[i] > 0 && left[i] > 0) k += 1;
            ret = std::max(ret, k);
        }
        return ret;


    }
};





int main(){
    TreeNode n5(5);
    TreeNode n3(3);
    TreeNode n32(3);
    TreeNode n9(3);
    TreeNode n2(2);
    TreeNode n1(1);
    n1.left = &n3;
    // n1.right = &n2;
    n3.left = &n5;
    n3.right = &n32;
    //n2.right = &n9;
    Solution so;
    cout << so.widthOfBinaryTree(&n1);

}










