1class Solution {
2public:
3    void set (unordered_map<int,int>& mp , vector<int>&arr1 , bool f) {
4        for (int i = 0 ; i < arr1.size() ; i += 1) {
5            int num = arr1[i];
6            while (num) {
7                if (f) mp[num] = 1;
8                else if (mp[num]) mp[num] += 1;
9                num /= 10;
10            }
11        }
12    }
13    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
14        ios_base::sync_with_stdio(false);
15        unordered_map<int,int> mp;
16        set (mp,arr1,true);
17        set (mp,arr2,false);
18        int _max = INT_MIN , size;
19        for (auto& i : mp){
20            if (i.second >= 2){
21                size = (log10(i.first) + 1);
22                _max = max(size , _max);
23            }
24        }
25        return max (_max , 0 );
26    }
27};