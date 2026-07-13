class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        // cout << "[";

        // for (int i = 0; i < pairs.size(); i++) {
        //     cout << "[" << pairs[i][0] << ", " << pairs[i][1] << "]";

        //     if (i != pairs.size() - 1) {
        //         cout << ", ";
        //     }
        // }

        // cout << "]" << endl;
        int n = pairs.size();
        int end = pairs[0][1];
        int cnt = 1;
        // int mx = 1;
    // cout << end << " ";
        for (int i = 1; i < n; i += 1) {
            if (end < pairs[i][0]) {
                end = pairs[i][1];
                cnt += 1;
            } else {
                // mx = max (mx, cnt);
                end = min(end, pairs[i][1]);
            }
            // cout << end << " ";
        }
        return cnt;
        // return 4;
    }
};