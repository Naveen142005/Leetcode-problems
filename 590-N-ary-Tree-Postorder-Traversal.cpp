/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postOrder(Node* root ,  vector<int>& ans ) {
        if (root != nullptr) {
            for (int i = 0 ; i < (root->children).size() ; i++ ) {
                postOrder (root->children[i] , ans);
                ans.push_back(root->children[i]->val);
            }
        }
    }
    vector<int> postorder(Node* root) {
        ios_base::sync_with_stdio(false);
         vector<int> ans;
         postOrder (root , ans);
         if (root) ans.push_back(root->val);
         return ans;
    }
};