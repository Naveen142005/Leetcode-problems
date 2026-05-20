1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int n;
15    unordered_map <int, int> preorder_index, inorder_index;
16    TreeNode* solve (vector<int>& preorder, vector <int>& inorder, int st, int end) {
17        if (st > end) return nullptr;
18
19        if (st == end) {
20            return new TreeNode(inorder[st]);
21        }
22
23        int min_index = INT_MAX;
24        int ac_index = INT_MAX;
25        
26        for (int i = st; i <= end; i += 1) {
27            // min_index = min (min_index, preorder_index[inorder[i]]);
28
29            if (min_index > preorder_index[inorder[i]]) {
30                min_index = preorder_index[inorder[i]];
31                ac_index = i;
32            }
33        }
34
35        // cout << st << " " << end << " " << min_index <<'\n';; 
36        TreeNode* new_node = new TreeNode(preorder[min_index]);
37
38        new_node -> left = solve (preorder, inorder, st, ac_index - 1);
39        new_node -> right = solve (preorder, inorder, ac_index + 1, end);
40
41        return new_node;
42    }
43    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
44        
45        n = preorder.size();
46        TreeNode* root  = new TreeNode(preorder[0]);
47    
48        for (int i = 0; i < n; i += 1) {
49            preorder_index[preorder[i]] = i;
50            inorder_index[inorder[i]]   = i;
51        }
52
53        for (int i = 0; i < n; i += 1) {
54            if (preorder[0] == inorder[i]) {
55                root -> left  = solve (preorder, inorder, 0, i - 1);
56                root -> right = solve (preorder, inorder,  i + 1, n - 1);
57            }
58        }
59        return root;
60    }
61};