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
    private: 
    int helper( TreeNode *root){
        if(!root) return 0;
        int lheight=helper(root->left);
        if(lheight==-1) return -1;
        int rheight=helper(root->right);
        if(rheight==-1) return -1;
        if(abs(lheight-rheight)>1) return -1;
        return 1+ max(lheight,rheight);

    }
public:
    bool isBalanced(TreeNode* root) {
       
        return helper(root)!= -1;
    }
};