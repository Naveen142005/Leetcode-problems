
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        ListNode *t = head, *temp, *null_temp, *p;
        vector<ListNode*> ans(k, nullptr);
        int n = 0, i = 0;
        for (t = head; t != nullptr; t = t->next)
            n++;
        int num = n / k, mod = n % k;
        t = head;
        k = n / k;
        while (t != nullptr) {
            temp = t;
            int y = 0;
            if (mod) {
                while (t && y != k) {
                    t = t->next;
                    y++;
                }
                p = t;
                ans[i] = temp;
                if (t) {
                    t = t->next;
                    p->next = nullptr;
                }
                mod--;
            } else {
                y = 1;
                while (t && y++ != k) 
                    t = t->next;
                
                p = t;
                ans[i] = temp;
                if (t) {
                    t = t->next;
                    p->next = nullptr;
                }
            }
            i++;
        }
        return ans;
    }
};