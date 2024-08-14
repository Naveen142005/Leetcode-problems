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
    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        int ans = 0;
        bool f = true;
        bool res = true;
        subFunction(ans, root, f, res);
        return res;
    }
    bool subFunction(int& ans, TreeNode* root, bool& f, bool& res) {
        if (root != nullptr) {
            subFunction(ans, root->left, f, res);
            if (f) {
                ans = root->val, f = 0;
            } else {
                if (ans >= root->val) {
                    res = false;
                    return 0;
                } else
                    ans = root->val;
            }
            subFunction(ans, root->right, f, res);
        }
        return true;
    }
  
};