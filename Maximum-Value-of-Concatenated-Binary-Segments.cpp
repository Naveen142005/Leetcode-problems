1class Solution {
2public:
3    using ll = long long;
4
5    ll power (ll base, ll n, const int& mod)  {
6        ll res = 1;
7
8        while (n) {
9            if (n & 1) res = (res * base) % mod;
10            base = (base * base) % mod;
11            n >>= 1;
12        }
13
14        return res;
15    }
16
17    int maxValue(vector<int>& nums1, vector<int>& nums0) {
18        ios::sync_with_stdio(false);
19        cin.tie(nullptr);
20        
21        vector<vector<int>> temp;
22        int n = nums1.size();
23        const int mod = 1e9+7;
24
25        int pow[200002];
26        pow[0] = 1;
27
28        for (int i = 1; i <= 200001; i += 1) {
29            pow[i] = (pow[i - 1] * 2) % mod; 
30        }
31        for (int i = 0; i < n; i++) {
32            temp.push_back({nums1[i], nums0[i]});
33        }
34
35        sort(temp.begin(), temp.end(), [](vector<int>& v1, vector<int>& v2) {
36            string s1 (v1[0], '1');
37            string s2 (v2[0], '1');
38            string s3 (v1[1], '0');
39            string s4 (v2[1], '0');
40
41            s1 += s3;
42            s2 += s4;
43
44            return s1 + s2 > s2 + s1;
45        });
46
47        int idx = 0;
48        int ans = 0;
49        for (int i = n - 1; i >= 0; i -= 1) {
50            int z = temp[i][1];
51            idx = (idx + z) % mod;
52
53            int o = temp[i][0];
54
55            while (o--) {
56                ans = (ans + pow[idx]) % mod;
57                idx += 1;
58            }
59            
60        }
61        return ans;
62    }
63};