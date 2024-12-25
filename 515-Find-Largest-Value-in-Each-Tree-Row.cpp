
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector <int> ans;
        q.push (root);
        while (!q.empty()) {
            int ss = q.size();
            int mx = INT_MIN;
            for (int i = 0 ; i < ss; i += 1) {
                TreeNode* rr = q.front();
                q.pop();
                mx = max (mx , rr -> val);
                if (rr -> left) q.push(rr -> left);
                if (rr -> right) q.push (rr -> right);
            }
            ans.push_back(mx);
        }        
        return ans;
    }
};