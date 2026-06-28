1class Solution {
2public:
3    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
4        sort(arr.begin(),arr.end());    
5        int n = arr.size();
6        int mx = arr[0];
7        arr[0] =  1;
8        for (int i = 1; i < n; i += 1) {
9            // cout << arr[i] << " ";
10            if (abs(arr[i - 1] - arr[i]) <= 1) {
11                mx = max (arr[i], mx);
12                continue;
13            }
14            else {
15                arr[i] = arr[ i - 1 ]  + 1;
16            }
17
18            mx = max (arr[i], mx);
19        }
20        return min(mx, n);
21    }
22};