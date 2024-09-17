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
    vector<vector<int>> ans;
    void subFunction (TreeNode* root, int t,vector<int> res) {
        if (root) {
            res.push_back(root->val);
            t -= root->val;
            if (!t && !root->left && !root->right) ans.push_back(res);
            subFunction(root->left,t,res);
            subFunction (root->right,t,res);
            res.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ios_base::sync_with_stdio(0);
        vector<int> res;
        subFunction (root,targetSum,res);
        return ans;
    }
};