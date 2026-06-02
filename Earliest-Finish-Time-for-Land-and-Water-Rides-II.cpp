1class Solution {
2public:
3
4    int solve (vector<int>& a1, vector<int>& a2, vector<int>& b1, vector<int>& b2) {
5        int mx = INT_MAX;
6        int n = a1.size();
7        for (int i = 0; i < n; i += 1) {
8            mx = min (mx, a1[i] + a2[i]);
9        }
10        int ans = INT_MAX;
11        for (int i = 0; i < b1.size(); i += 1) {
12            ans = min(ans, mx + max(b1[i], mx) - mx  + b2[i]);
13        }
14
15        return ans;
16    }
17    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
18        return min (
19            solve (landStartTime, landDuration, waterStartTime, waterDuration),
20            solve (waterStartTime, waterDuration, landStartTime, landDuration)
21        );
22    }
23};