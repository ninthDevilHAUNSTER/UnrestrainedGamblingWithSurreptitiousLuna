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
    vector<vector<int>> res;
    int freeNodes(TreeNode *root){
        if(root==nullptr)
            return 0;
        int left = freeNodes(root->left);
        int right = freeNodes(root->right);
        int h = max(left,right); // 对于叶子节点，最终将返回0.
        if(res.size() == h){
            res.push_back(vector<int>());
        }
        res[h].push_back(root->val);
        return h+1; // 上一层，h+1
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        // 反向定义深度
        freeNodes(root);
        return res;
    }
};