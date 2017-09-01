/**
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined
 between two nodes v and w as the lowest node in T that has both v and w as descendants
 (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example
 is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according
 to the LCA definition.
 *
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

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
private:
    enum DIR {
        LEFT, RIGHT
    };

    int find(TreeNode *root, TreeNode *p, vector<DIR> &record) {
        if(root == nullptr) return 0;
        if (p == root) return 1;
        if (root->left != nullptr) {
            record.push_back(LEFT);
            if (find(root->left, p, record)) {
                return 1;
            } else {
                record.pop_back();
            }
        }

        if (root->right != nullptr) {
            record.push_back(RIGHT);
            if (find(root->right, p, record)) {
                return 1;
            } else {
                record.pop_back();
            }
        }
        return 0;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<DIR> vp, vq;
        if(!find(root, p, vp) || !find(root, q, vq)) return nullptr;

//        for(auto a : vp){
//            cout << (a == LEFT ? "left" : "right" ) << endl;
//        }
//        for(auto a : vq){
//            cout << (a == LEFT ? "left" : "right" ) << endl;
//        }
        vector<DIR> lca;
        auto ip = vp.begin(), iq = vq.begin();
        while (ip != vp.end() && iq != vq.end()) {
            if (*ip != *iq) break;
            lca.push_back(*ip);
            ++ip;
            ++iq;
        }

        TreeNode *result = root;
        for (auto k : lca) {
            if (k == LEFT) {
                result = result->left;
            } else {
                result = result->right;
            }
        }
        return result;

    }
};

int main(){
    TreeNode a(37);
    TreeNode b(-34);
    TreeNode c(-48);
    TreeNode d(-100);
    TreeNode e(-100);
    TreeNode j(48);
    TreeNode i(-54);
    TreeNode h(-71);
    TreeNode g(-22);
    TreeNode f(8);

    a.left = &b; a.right = &c;
    b.right = &d;
    c.left = &e; c.right = &j;
    j.left = &i;
    i.left = &h; i.right = &g;
    g.right = &f;

    auto k = Solution().lowestCommonAncestor(&a, &h, &j);
    cout << k->val;

}





















