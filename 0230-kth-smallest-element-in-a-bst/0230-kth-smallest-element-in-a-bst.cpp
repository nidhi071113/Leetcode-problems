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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        int n = v.size();
        int kth_small = v[k-1];
        return kth_small;
    }
    void inorder(TreeNode* root,vector<int> &v){
        if(root == nullptr) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
};