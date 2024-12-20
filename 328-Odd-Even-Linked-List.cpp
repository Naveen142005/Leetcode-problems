
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head -> next || !(head -> next -> next)) return head;
        ListNode *temp = nullptr, *i = head, *j = head->next, *temp_1 = nullptr;
        ListNode* tail = head->next;
        while (i && j) {
            if (i->next && i->next->next == nullptr) {
                if (temp) temp->next = nullptr;
                break;
            }
            temp = i->next->next;
            if (j->next)
                temp_1 = j->next->next;
            if (i->next)
                i->next = i->next->next;
            else
                i->next = nullptr;

            if (j->next)
                j->next = j->next->next;
            else
                j->next = nullptr;

            i = temp;
            j = temp_1;
        }

        i -> next = tail;
        return head;
    }
};