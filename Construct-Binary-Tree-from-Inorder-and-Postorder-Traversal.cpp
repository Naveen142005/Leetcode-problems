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
15    unordered_map <int, int> postorder_index, inorder_index;
16    TreeNode* solve (vector<int>& postorder, vector <int>& inorder, int st, int end) {
17        if (st > end) return nullptr;
18
19        if (st == end) {
20            return new TreeNode(inorder[st]);
21        }
22
23        int min_index = INT_MIN;
24        int ac_index = INT_MIN;
25
26        for (int i = st; i <= end; i += 1) {
27            if (min_index < postorder_index[inorder[i]]) {
28                min_index = postorder_index[inorder[i]];
29                ac_index = i;
30            }
31        }
32
33       
34        TreeNode* new_node = new TreeNode(postorder[min_index]);
35
36        new_node -> left = solve (postorder, inorder, st, ac_index - 1);
37        new_node -> right = solve (postorder, inorder, ac_index + 1, end);
38
39        return new_node;
40    }
41    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
42        n = postorder.size();
43        TreeNode* root  = new TreeNode(postorder[n - 1]);
44    
45        for (int i = 0; i < n; i += 1) {
46            postorder_index[postorder[i]] = i;
47            inorder_index[inorder[i]]   = i;
48        }
49
50        for (int i = 0; i < n; i += 1) {
51            if (postorder[n - 1] == inorder[i]) {
52                root -> left  = solve (postorder, inorder, 0, i - 1);
53                root -> right = solve (postorder, inorder,  i + 1, n - 1);
54            }
55        }
56        return root;
57    }
58};
59
60
61