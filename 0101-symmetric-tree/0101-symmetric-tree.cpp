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
    bool isSymmetric(TreeNode* root) {
        vector<vector<int>> bfs;
        
        if(root==NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node==NULL) {level.push_back(-101);continue;}
                level.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            bfs.push_back(level);
        }

        for(int i=1;i<bfs.size();i++){
            vector<int> temp=bfs[i];
            int siz=temp.size();
            for(int i=0;i<siz/2;i++){
                if(temp[i]!=temp[siz-i-1]) return false;
            }
        }
        return true;
    }
};