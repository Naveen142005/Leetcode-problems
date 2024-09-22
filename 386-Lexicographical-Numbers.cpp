class Solution {
public:
    void subFunction(int curr, int n, vector<int>& res) {
        int cnt = 0;
        for (int i = curr; i <= n && cnt <= 9; i++) {
            if (res.size() == n)
                break;
            cnt += 1;
            if (i < curr + 10)
                res.push_back(i);
            if (i * 10 <= n)
                subFunction(i * 10, n, res);
        }
    }
    vector<int> lexicalOrder(int n) {
        ios_base::sync_with_stdio(false);
        vector<int> res;
        subFunction(1, n, res);

        return res;
    }
};