1class Solution {
2public:
3    struct Node {
4        int mx;
5        int mi;
6    };
7    
8    int n;
9    vector <Node> seg;
10
11    Solution() {
12    }
13
14    Node merge (Node x, Node y) {
15        return {
16            max (x.mx, y.mx),
17            min (x.mi, y.mi)
18        };
19    }
20
21    void build (int left, int right, int idx, vector<int>& nums) {
22
23        if (left == right) {
24            seg[idx].mx = nums[left];
25            seg[idx].mi = nums[right];
26            return;
27        }
28
29        int mid = (left + right) / 2;
30        build (left, mid, 2 * idx + 1, nums);
31        build (mid + 1, right, 2 * idx + 2, nums);
32        seg[idx] = merge (seg[2 * idx + 1], seg[2 * idx + 2]);
33    }
34    
35    Node query (int st, int end, int left, int right, int idx) {
36        if (left > end || right < st) return {INT_MIN , INT_MAX};
37
38        if (st <= left && right <= end) return seg[idx];
39
40        int mid = (left + right) / 2;
41        Node l = query (st, end, left, mid, 2 * idx + 1);
42        Node r =  query (st, end, mid + 1, right, 2 * idx + 2);
43        return merge (l, r);
44        
45    }
46    long long maxTotalValue(vector<int>& nums, int k) {
47        ios::sync_with_stdio(false);
48        cin.tie(nullptr);
49        
50        using ll = long long;
51        using t = tuple <ll,int,int>;
52        priority_queue <t> pq;
53
54        n = nums.size();
55        seg.resize(4 * n);
56        build (0 , n - 1, 0, nums);
57
58        Node q = query(0, n - 1, 0, n - 1, 0);
59        pq.push ({q.mx - q.mi, 0, n - 1});
60
61        long long ans = 0;
62        unordered_set <int> visited;
63
64        auto ch = [&](int i, int j) {
65            return 1LL* i * n + j;
66        };
67
68        while (pq.size() && k) {
69            auto [val, idx, jdx] = pq.top();
70            pq.pop();
71            ans += val;
72
73            if (jdx - 1 >= 0 && idx <= jdx - 1  && !(visited.find(ch(idx, jdx - 1)) != visited.end())) {
74                Node qj = query (idx, jdx - 1, 0, n - 1, 0);
75                pq.push ({qj.mx - qj.mi, idx, jdx - 1});
76                visited.insert(ch(idx, jdx - 1));
77            }
78
79            if (idx + 1 < n && idx + 1 <= jdx && !(visited.find(ch(idx + 1, jdx)) != visited.end())) {
80                Node qi = query (idx + 1, jdx, 0, n - 1, 0);
81                pq.push ({qi.mx - qi.mi, idx + 1, jdx});
82                visited.insert(ch(idx + 1, jdx));
83            }
84            k -= 1;
85        }
86
87        return ans;
88        
89        // return 1;
90    }
91};