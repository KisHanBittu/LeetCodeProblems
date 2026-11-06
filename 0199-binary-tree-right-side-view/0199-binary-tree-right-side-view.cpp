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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<int> res;
        queue<TreeNode*> q;
        TreeNode* t =nullptr;
        q.push(root);
        while(!q.empty()){
            int lvlSize = q.size();
            while(lvlSize--){
                t = q.front();
                q.pop();

                if(t->left != nullptr){
                    q.push(t->left);
                }
                if(t->right != nullptr){
                    q.push(t->right);
                }

            }
            res.push_back(t->val);
        }
        return res;
        
    }
};