1class Solution {
2public:
3    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
4        ios::sync_with_stdio(false);
5        cin.tie(nullptr);
6        
7        unordered_set <int> s;
8        int n = A.size();
9        vector <int> ans (n, 0);
10        for (int i = 0; i < n;  i += 1) {
11            s.insert(A[i]);
12            s.insert(B[i]);
13            int ss = s.size();
14            ans[i] = abs (ss - (i + 1) * 2);
15        }
16        return ans;
17    }
18};