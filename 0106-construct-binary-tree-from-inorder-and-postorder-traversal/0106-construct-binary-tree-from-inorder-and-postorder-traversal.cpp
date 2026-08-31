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

    TreeNode* solve(vector<int> &postorder,int postSt,int postEnd,int inSt,int inEnd){
        
        if(inSt > inEnd) return nullptr;

        int rootval = postorder[postEnd];
        TreeNode* root = new TreeNode(rootval);

        int pos = mp[rootval];
        int leftsize = pos - inSt;

        root->right = solve(postorder,postSt+leftsize,postEnd-1,pos+1,inEnd);
        root->left = solve(postorder,postSt,postSt+leftsize-1,inSt,pos-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return solve(postorder,0,postorder.size() - 1,0,inorder.size() - 1);
    }
};