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
    int ans=0;

    int Diameter(TreeNode* node){
        if(node==NULL) return 0;
        int left=Diameter(node->left);
        int right=Diameter(node->right);
        ans=max(ans,left+right);
        return 1+max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // return height(root->left)+height(root->right);
        
        Diameter(root);
        return ans;
    }
};