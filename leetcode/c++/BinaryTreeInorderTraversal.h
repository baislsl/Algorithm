//
// Created by baislsl on 17-3-5.
//

#ifndef LEETCODE_BINARYTREEINORDERTRAVERSAL_H
#define LEETCODE_BINARYTREEINORDERTRAVERSAL_H

#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class BinaryTreeInorderTraversal {
public:
    static vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> stack;
        vector<int > ans;
        bool flag = true;
        stack.push(root);
        while(!stack.empty()){
            root = stack.top();
            stack.pop();
            if(flag)
                while(root->left != NULL){
                    stack.push(root);
                    root = root->left;
                }
            ans.push_back(root->val);
            if(root->right != NULL){
                stack.push(root->right);
                flag = true;
            }else{
                flag = false;
            }
        }
        return ans;
    }
};


#endif //LEETCODE_BINARYTREEINORDERTRAVERSAL_H
