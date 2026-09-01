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
    int maxSum = 0;
public:
    struct NodeInfo {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };
    
    NodeInfo helper(TreeNode* root) {
        if (!root) return {true, INT_MAX, INT_MIN, 0};
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currSum);
            return {true, min(root->val, left.minVal), max(root->val, right.maxVal), currSum};
        }
        
        return {false, 0, 0, 0};
    }
    
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
