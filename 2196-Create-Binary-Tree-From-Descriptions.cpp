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
 #include <algorithm>
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        for (int i = 0; i < descriptions.size(); i++) {
            TreeNode* tn = new TreeNode(descriptions[i][1]);
            tn->left = tn->right = nullptr;
             mp[descriptions[i][1]] = tn;
        }
         TreeNode* root;
         for (int i = 0; i < descriptions.size(); i++) {
            if(mp[descriptions[i][0]]);else{
                root = new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]] = root;
                break;
            }
         }
         for (int i = 0; i < descriptions.size(); i++) {
            if (descriptions[i][2]) {
                mp[descriptions[i][0]] ->left = mp[descriptions[i][1]];
            }
            else
               mp[descriptions[i][0]] ->right = mp[descriptions[i][1]];
         }
        return root;
    }
}
;