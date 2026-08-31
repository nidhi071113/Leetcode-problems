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
    unordered_map<int,int> mp;

    TreeNode* solve(vector<int>& preorder, int preStart, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int pos = mp[rootVal];
        int leftSize = pos - inStart;

        root->left = solve(preorder, preStart + 1, inStart, pos - 1);
        root->right = solve(preorder, preStart + leftSize + 1, pos + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return solve(preorder, 0, 0, inorder.size() - 1);
    }
};