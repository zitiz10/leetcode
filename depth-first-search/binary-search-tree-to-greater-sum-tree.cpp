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
    int sum=0;
    void RevInOrder(TreeNode*root){
        if(!root) return ;
    
        RevInOrder(root->right);
        sum+=root->val;
        root->val=sum;
        RevInOrder(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        sum=0;
        RevInOrder(root);
        return root;
    }
};