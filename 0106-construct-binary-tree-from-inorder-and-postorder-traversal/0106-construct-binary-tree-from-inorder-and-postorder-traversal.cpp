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
    int idx[6001];

    TreeNode* solve(vector<int>& postorder, int postSt, int postEnd, int inSt, int inEnd) {
        if (inSt > inEnd) return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int pos = idx[rootVal + 3000];
        int leftSize = pos - inSt;

        root->right = solve(postorder, postSt + leftSize, postEnd - 1, pos + 1, inEnd);
        root->left = solve(postorder, postSt, postSt + leftSize - 1, inSt, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < (int)inorder.size(); i++) {
            idx[inorder[i] + 3000] = i;
        }
        return solve(postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
};