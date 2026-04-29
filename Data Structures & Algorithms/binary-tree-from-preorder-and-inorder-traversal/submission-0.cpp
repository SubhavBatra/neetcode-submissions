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
    TreeNode* fun(int prestart, int preend, int instart, int inend, vector<int>& preorder, vector<int>& inorder, map<int,int>& mp){
        if(prestart>preend || instart>inend) return nullptr;
        TreeNode* node = new TreeNode(preorder[prestart]);
        int elem = mp[node->val];
        int nelem = elem - instart;
        node->left = fun(prestart+1, prestart+nelem, instart, elem-1, preorder, inorder, mp);
        node->right = fun(prestart+nelem+1, preend, elem+1, inend, preorder, inorder, mp);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prestart = 0, preend = preorder.size()-1, instart = 0, inend = inorder.size()-1;
        map<int,int> mp;
        for(int i=instart; i<=inend; i++){
            mp[inorder[i]]=i;
        }
        return fun(prestart, preend, instart, inend, preorder, inorder, mp);
    }
};
