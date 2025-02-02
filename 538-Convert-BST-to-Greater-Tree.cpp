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
    void solve(int& t , TreeNode* root) {
        if (root) {
            t += root -> val;
            solve (t , root -> left);
            solve (t , root -> right);
        }
    }
    void inorder (TreeNode* root , int& tot , int& temp) {
        if (root) {
            inorder(root -> left, tot , temp);
            temp = root -> val;
            root -> val = tot;
            tot -= temp;
            inorder(root -> right, tot , temp);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
         int tot = 0;
        solve (tot , root);
        int temp = 0;
        inorder(root , tot ,temp);
        return root;
    }
};