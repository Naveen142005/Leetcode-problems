class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        int cnt = 1;
        typedef ListNode pp;
        pp* i = head, *l = nullptr, *pre = nullptr, *prev = nullptr, *next = nullptr;

        while (cnt < left) {
            pre = i;
            i = i->next;
            cnt++;
        }

        l = pre;
        pp* start = i;

        while (cnt <= right) {
            next = i->next;
            i->next = prev;
            prev = i;
            i = next;
            cnt++;
        }

        if (l) {
            l->next = prev;
        } else {
            head = prev;
        }

        start->next = i;

        return head;
    }
};
