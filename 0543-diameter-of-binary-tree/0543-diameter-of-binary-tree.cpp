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

    int dfs(TreeNode* node){
        if(node==NULL) return 0;
        int lft=dfs(node->left);
        int rit=dfs(node->right);

        ans = max(ans,lft+rit);
        return max(lft,rit)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};