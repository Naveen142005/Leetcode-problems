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
    struct cmp{
        bool operator()(ListNode* l1 , ListNode* l2) {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(false);
        priority_queue<ListNode* , vector<ListNode*> , cmp > pq;
        ListNode* head = nullptr;
        for (int i = 0; i < lists.size() ; i += 1 ) {
            head = lists[i];
            while (head) {
                pq.push(head);
                head = head -> next;
            }
        }
        if (pq.empty()) return nullptr;
        
        ListNode* ans = pq.top();
      
        while (!pq.empty()) {
                head = pq.top();
                pq.pop();
               if (!pq.empty()) head -> next = pq.top();
               else head ->next = nullptr;
        }
        
        return ans;

    }
};