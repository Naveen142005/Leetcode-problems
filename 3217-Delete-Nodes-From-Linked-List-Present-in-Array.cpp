/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ios_base::sync_with_stdio(0);
        vector<int> e;
        unordered_map<int,int> mp;
        for (auto i : nums) mp[i] = 1;
        ListNode* temp = nullptr , *null;
        for (temp = head ; temp != nullptr ; temp = temp->next){
            if (!mp[temp->val]) {
                e.push_back(temp->val);
            }
        }
        temp = head;
        for (auto i : e) {
            temp->val = i;
            null = temp;
            temp = temp->next;
        }
       if (temp) null->next = nullptr;
        return head;
    }
};