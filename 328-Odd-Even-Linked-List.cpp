
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !(head->next->next))
            return head;
        ListNode *odd = nullptr, *i = head, *j = head->next, *even = nullptr,*tail = head->next;
        while (i && j) {
            if (i->next && i->next->next == nullptr) {
                if (odd) odd->next = nullptr;
                break;
            }
            odd = i->next->next;
            even = j->next ? j->next->next : nullptr;
            i->next = i->next ? i->next->next : nullptr;
            j->next = j->next ? j->next->next : nullptr;

            i = odd;
            j = even;
        }

        i->next = tail;
        return head;
    }
};