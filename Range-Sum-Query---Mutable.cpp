1class NumArray {
2public:
3    vector<int> seg;
4    vector<int> nums;
5    NumArray(vector<int>& nums) {
6        int n = 4 * nums.size() + 1;
7        this->nums = nums;
8        seg.resize(n);
9        buildTree(0, nums.size() - 1, 0);
10    }
11    int buildTree(int left, int right, int idx) {
12        if (left > right)
13            return 0;
14        if (left == right) {
15            return seg[idx] = nums[left];
16        }
17        int mid = (left + right) / 2;
18        int l = buildTree(left, mid, 2 * idx + 1);
19        int r = buildTree(mid + 1, right, 2 * idx + 2);
20        return seg[idx] = l + r;
21    }
22
23    int up(int left, int right, int tar, int val, int idx) {
24        // cout << left << " " << right <<" " << idx<<  endl;
25        if (left > right)
26            return 0;
27        if (left == tar && right == tar) {
28            seg[idx] = val;
29            return val - nums[left];
30        }
31        int mid = (left + right) / 2;
32        int l, r, c;
33        l = r = c = 0;
34        if (mid < tar) {
35            l = up(mid + 1, right, tar, val, 2 * idx + 2);
36            seg[idx] += l;
37            return l;
38        } else if (mid >= tar) {
39            r = up(left, mid, tar, val, 2 * idx + 1);
40            seg[idx] += r;
41            return r;
42        }
43
44        return 0;
45    }
46
47    void update(int index, int val) {
48        up(0, this->nums.size() - 1, index, val, 0);
49        nums[index] = val;
50    }
51
52    int query(int st, int end, int left, int right, int idx) {
53        if (end < left || st > right)
54            return 0;
55
56        if (st <= left && right <= end) {
57            return seg[idx];
58        }
59
60        int mid = (left + right) / 2;
61
62        int l = query(st, end, left, mid, 2 * idx + 1);
63        int r = query(st, end, mid + 1, right, 2 * idx + 2);
64
65        return l + r;
66    }
67
68    int sumRange(int left, int right) {
69        return query(left, right, 0, this->nums.size() - 1, 0);
70    }
71};
72
73/**
74 * Your NumArray object will be instantiated and called as such:
75 * NumArray* obj = new NumArray(nums);
76 * obj->update(index,val);
77 * int param_2 = obj->sumRange(left,right);
78 */