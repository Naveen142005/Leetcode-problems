1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
10 * right(right) {}
11 * };
12 */
13 #include <algorithm>
14class Solution {
15public:
16    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
17        unordered_map<int, TreeNode*> mp;
18        for (int i = 0; i < descriptions.size(); i++) {
19            TreeNode* tn = new TreeNode(descriptions[i][1]);
20            tn->left = tn->right = nullptr;
21             mp[descriptions[i][1]] = tn;
22        }
23         TreeNode* root;
24         for (int i = 0; i < descriptions.size(); i++) {
25            if(mp[descriptions[i][0]]);else{
26                root = new TreeNode(descriptions[i][0]);
27                mp[descriptions[i][0]] = root;
28                break;
29            }
30         }
31         for (int i = 0; i < descriptions.size(); i++) {
32            if (descriptions[i][2]) {
33                mp[descriptions[i][0]] ->left = mp[descriptions[i][1]];
34            }
35            else
36               mp[descriptions[i][0]] ->right = mp[descriptions[i][1]];
37         }
38        return root;
39    }
40}
41;