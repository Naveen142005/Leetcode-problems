
static const int __ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode *prev = nullptr, *next = nullptr, *curr = head;
        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head -> next)  return head;
        ListNode *i = head, *ans = nullptr, *temp, *next, *res, *ptr;
        int count;
        while (i != nullptr) {
            ptr = i;
            count = 1;

            while (count != 2 && i->next) {
                i = i->next;
                count++;
            }

            if (i)
                next = i->next;
            if (count == 2) {
                res = reverse(ptr, i->next);
                if (ans == nullptr) {
                    ans = res;
                    temp = ptr;
                } else {
                    temp->next = res;
                    temp = ptr;
                }
            }
            if (!i)
                break;
            i = next;
        }
        if (count != 2)
            temp->next = ptr;
        return ans;
    }
};