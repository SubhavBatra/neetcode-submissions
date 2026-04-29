/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void fun(TreeNode* node, vector<int>& ans, int depth){
        if(!node) return;

        if(ans.size()==depth) ans.push_back(node->val);

        fun(node->right, ans, depth+1);
        fun(node->left, ans, depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        fun(root, ans, 0);
        return ans;
    }
};
