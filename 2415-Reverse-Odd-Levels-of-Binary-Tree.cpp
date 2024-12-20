class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<TreeNode*> nodes;
        q.push (root);
        int cnt = 0;

        while (!q.empty()) {
               int s = q.size();
               bool flag = false;
               for (int i = 0 ; i < s ; i += 1) {
                    TreeNode* node = q.front();
                    q.pop();

                    if(node->left!=NULL) q.push(node->left);
                    if(node->right!=NULL) q.push(node->right);

                if (cnt % 2) {
                    nodes.push_back(node);
                    flag = true;
                }
            }
    
            cnt += 1;
            int i = 0 , j = nodes.size() - 1;

            while (i < j) {
                swap (nodes[i]->val , nodes[j] -> val);
                i += 1;
                j -= 1;
            }
            nodes.clear();
        }
        return root;
    }
};