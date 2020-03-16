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
    int sum[100]; // 记录当前层叶子结点的权值和
    int res=0;
    int maxDepth = -1;
    void transfer(TreeNode *root,int depth){
        if(root->left == nullptr && root->right == nullptr){
            // cout << root->val << "\t";
            maxDepth = max(maxDepth,depth);
            sum[depth]+= root->val;
        }
        if(root->right!=nullptr)
            transfer(root->right,depth+1);
        if(root->left!=nullptr)
            transfer(root->left,depth+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        transfer(root,0);
        // for(int i=0;i<20;i++) cout << sum[i] << "\t";
        return sum[maxDepth];

    }
};