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
    
    int dfs(TreeNode* node){
        if(node==NULL){
            return 0;
        }

        int lft = dfs(node->left);
        int rit = dfs(node->right);

        if(lft==-1 || rit==-1)return -1;
        if(abs(lft-rit)>1){
            return -1;
        }

        return max(lft,rit)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(dfs(root)==-1)return false;
        return true;
    }
};