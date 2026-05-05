1class Solution {
2public:
3    ListNode* rotateRight(ListNode* head, int k) {
4        ListNode* ptr = head, *last;
5        if (!k) return head;
6        int cnt = 0;
7        while (ptr) {
8            cnt += 1;
9            last = ptr;
10            ptr = ptr->next;
11        }
12
13        if (!cnt) return head;
14        k %= cnt;
15        if (!k) return head;
16
17
18        int i = 1;
19        ptr = head;
20        while (i < cnt - k) {
21            ptr = ptr -> next;
22            i += 1;
23        }
24        last->next = head;
25        head = ptr->next;
26        ptr->next = nullptr;
27
28        return head;
29    }
30};