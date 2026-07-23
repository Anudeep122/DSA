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

    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        if(root==NULL) return true;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            int diff=abs(height(node->left)-height(node->right));
            if(diff>1) return false;
            if(node->right!=NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left);
        }   

        return true;   
    }
};