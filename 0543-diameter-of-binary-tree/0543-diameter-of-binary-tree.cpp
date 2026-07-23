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
    int height(TreeNode* node){
        if(node==NULL) return 0;
        return 1+max(height(node->left),height(node->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // return height(root->left)+height(root->right);
        stack<TreeNode*> st;
        if(root==NULL) return 0;
        st.push(root);
        int ans=INT_MIN;
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            ans=max(ans,height(node->left)+height(node->right));
            if(node->left!=NULL) st.push(node->left);
            if(node->right!=NULL) st.push(node->right);
        }
        return ans;
    }
};