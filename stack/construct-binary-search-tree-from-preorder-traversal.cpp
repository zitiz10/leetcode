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
    TreeNode* buildBST(TreeNode*root,int val){
        if(!root) return new TreeNode(val);
        else if (val<root->val){
            root->left=buildBST(root->left,val);
        }
        else if (val>root->val){
            root->right=buildBST(root->right,val);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=NULL;
        for(int val : preorder){
            root=buildBST(root,val);
        }
        return root;
    }
};