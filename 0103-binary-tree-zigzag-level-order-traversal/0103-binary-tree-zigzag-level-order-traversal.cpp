/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        if (root == nullptr) {
            return res;
        }
        bool leftToRight = 1;
        while (!q.empty()) {
            int lvlSize = q.size();
            vector<int> temp;
            while (lvlSize--) {
                TreeNode* t = q.front();
                q.pop();
                    temp.push_back(t->val);
                    if (t->left != nullptr) {
                        q.push(t->left);
                    }
                    if (t->right != nullptr) {
                        q.push(t->right);
                    }
            
            }
            if(!leftToRight){
                reverse(temp.begin(),temp.end());
            }
            res.push_back(temp);
            leftToRight = !leftToRight;
        }
        return res;
    }
};