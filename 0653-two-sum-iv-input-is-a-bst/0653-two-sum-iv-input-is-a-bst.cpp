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
    // unordered_set<int> seen;

    // bool findTarget(TreeNode* root, int k) {
    //     if (!root) return false;

    //     if (seen.count(k - root->val)) return true;

    //     seen.insert(root->val);

    //     return findTarget(root->left, k) || findTarget(root->right, k);
    // }

    void inorder(TreeNode* root,vector<int> &res){
        if(root == NULL) return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        inorder(root,res);
        int left = 0 , right = res.size() - 1;
        while(left < right){
            int sum = res[left] + res[right];
            if(sum == k) return true;
            if(sum < k) left++;
            else right--;
        }
        return false;
    }
};
