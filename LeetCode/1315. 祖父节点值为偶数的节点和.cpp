//
// Created by shaob on 2020/3/16.
//

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
    int sum=0;
//    void calculate(TreeNode* root,TreeNode *father,TreeNode *grandfather){
//        if(grandfather!=nullptr && grandfather->val%2 == 0) {
////            cout << grandfather->val <<"\t";
//            sum+=grandfather->val;
//            /*
//             * 我写的有个很大的问题。
//             * 这里的sum会被重复计算，如果是PAT，我标个vis数组就行了，关键这里的treeNode不能改。
//             * 显然我这样是回溯的，那么不回溯就行了咯。
//             */
//        }
//        if(root->left!=nullptr) calculate(root->left, root, father);
//        if(root->right!=nullptr) calculate(root->right, root, father);
//    }
    void dfs(TreeNode* grandparent, TreeNode* parent, TreeNode* node) {
        if (!node) {
            return;
        }
        if (grandparent->val % 2 == 0) {
            sum += node->val;
        }
        dfs(parent, node, node->left);
        dfs(parent, node, node->right);
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        if (root->left) {
            dfs(root, root->left, root->left->left);
            dfs(root, root->left, root->left->right);
        }
        if (root->right) {
            dfs(root, root->right, root->right->left);
            dfs(root, root->right, root->right->right);
        }
        return sum;
    }
//    int sumEvenGrandparent(TreeNode* root) {
//        calculate(root,nullptr,nullptr);
//        return sum;
//    }
};