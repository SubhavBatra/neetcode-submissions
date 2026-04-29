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
    void traversal(TreeNode* node, vector<int>& arr){
        if(!node) return;

        traversal(node->left, arr);
        arr.push_back(node->val);
        traversal(node->right, arr);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        traversal(root, arr);
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};
