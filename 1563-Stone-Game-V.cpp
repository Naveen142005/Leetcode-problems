class Solution {
public:
    int n;
    vector<int> prex;
    int dp[501][501];
    int solve_(int l, int r) {

        // cout << "\n====================================\n";
        // cout << "solve_(" << l << ", " << r << ")\n";

        if (l >= r) {
            // cout << "Base case -> return 0\n";
            // cout << "====================================\n";
            return 0;
        }

        int res = 0;
        if (dp[l][r] != -1) return dp[l][r];

        for (int i = l; i < r; i++) {

            int lv = prex[i] - (l > 0 ? prex[l - 1] : 0);
            int rv = prex[r] - prex[i];

            // cout << "\n------------------------------------\n";
            // cout << "Range       : [" << l << ", " << r << "]\n";
            // cout << "Split       : " << i << "\n";
            // cout << "Left part   : [" << l << ", " << i << "]\n";
            // cout << "Right part  : [" << i + 1 << ", " << r << "]\n";
            // cout << "Left value  : " << lv << "\n";
            // cout << "Right value : " << rv << "\n";

            if (lv < rv) {

                // cout << "Decision    : LEFT < RIGHT\n";
                // cout << "Choosing    : LEFT\n";

                int val = solve_(l, i) + lv;

                // cout << "Value       : " << val << "\n";

                res = max(res, val);
            } else if (lv > rv) {

                // cout << "Decision    : LEFT > RIGHT\n";
                // cout << "Choosing    : RIGHT\n";

                int val = solve_(i + 1, r) + rv;

                // cout << "Value       : " << val << "\n";

                res = max(res, val);
            } else {

                // cout << "Decision    : LEFT == RIGHT\n";
                // cout << "Choosing    : BOTH\n";

                int leftResult = solve_(l, i);
                int rightResult = solve_(i + 1, r);

                int val = max(leftResult, rightResult) + lv;

                // cout << "Left result : " << leftResult << "\n";
                // cout << "Right result: " << rightResult << "\n";
                // cout << "Value       : " << val << "\n";

                res = max(res, val);
            }

            // cout << "Current res : " << res << "\n";
        }

        // cout << "\n>>> RETURN solve_(" << l << ", " << r << ") = " << res
            //  << "\n";
        // cout << "====================================\n";

        return dp[l][r] =  res;
    }
    int solve(int left, int right, vector<int>& nums, vector<int>& prex) {

        if (left >= right)
            return 0;

        int mid = (left + right) / 2;
        int tot = (right - left + 1);

        int leftVal = 0;
        int rightVal = 0;

        int res = 0;

        cout << "\n========================================\n";
        cout << "Range      : [" << left << ", " << right << "]\n";
        cout << "mid        : " << mid << "\n";
        cout << "length     : " << tot << "\n";
        cout << "========================================\n";

        if (tot & 1) {

            leftVal = prex[mid - 1] - (left > 0 ? prex[left - 1] : 0);
            rightVal = prex[right] - prex[mid - 1];

            cout << "Case       : ODD\n";
            cout << "Left range : [" << left << ", " << mid - 1 << "]\n";
            cout << "Right range: [" << mid << ", " << right << "]\n";
            cout << "leftVal    : " << leftVal << "\n";
            cout << "rightVal   : " << rightVal << "\n";

            if (leftVal == rightVal) {

                cout << "Decision   : EQUAL\n";
                cout << "Going to both sides\n";

                int leftRes = solve(left, mid - 1, nums, prex) + leftVal;
                int rightRes = solve(mid, right, nums, prex) + rightVal;

                cout << "leftRes    : " << leftRes << "\n";
                cout << "rightRes   : " << rightRes << "\n";

                res = max(leftRes, rightRes);
            } else if (leftVal < rightVal) {

                cout << "Decision   : LEFT < RIGHT\n";
                cout << "Going LEFT\n";

                res = solve(left, mid - 1, nums, prex) + leftVal;
            } else {

                cout << "Decision   : LEFT > RIGHT\n";
                cout << "Going RIGHT\n";

                res = solve(mid, right, nums, prex) + rightVal;
            }
        }

        else {

            leftVal = prex[mid] - (left > 0 ? prex[left - 1] : 0);
            rightVal = prex[right] - prex[mid];

            cout << "Case       : EVEN\n";
            cout << "Left range : [" << left << ", " << mid << "]\n";
            cout << "Right range: [" << mid + 1 << ", " << right << "]\n";
            cout << "leftVal    : " << leftVal << "\n";
            cout << "rightVal   : " << rightVal << "\n";

            if (leftVal == rightVal) {

                cout << "Decision   : EQUAL\n";
                cout << "Going to both sides\n";

                int leftRes = solve(left, mid, nums, prex) + leftVal;
                int rightRes = solve(mid + 1, right, nums, prex) + rightVal;

                cout << "leftRes    : " << leftRes << "\n";
                cout << "rightRes   : " << rightRes << "\n";

                res = max(leftRes, rightRes);
            } else if (leftVal < rightVal) {

                cout << "Decision   : LEFT < RIGHT\n";
                cout << "Going LEFT\n";

                res = solve(left, mid, nums, prex) + leftVal;
            } else {

                cout << "Decision   : LEFT > RIGHT\n";
                cout << "Going RIGHT\n";

                res = solve(mid + 1, right, nums, prex) + rightVal;
            }
        }

        cout << "RETURN     : " << res << "\n";
        cout << "========================================\n";

        return res;
    }

    int stoneGameV(vector<int>& nums) {
        n = nums.size();
        prex.clear();
        prex.push_back(nums[0]);
        memset (dp, -1, sizeof(dp));
        // cout << prex[0] << " ";
        for (int i = 1; i < n; i += 1) {
            prex.push_back(prex.back() + nums[i]);
            // cout << prex[i] << " ";
        }
        // cout << endl;
        // cout << 0 << " " << n - 1 << endl;
        // return solve(0, n - 1, nums, prex);
        // return 3;

        return solve_(0, n - 1);
    }
};
// 0 1 2 3 4 5
// 6 2 3 4 4 5
/*
left = 0
mid = 3
right = 5
*/

// 0 1 2
// 3 4 5
// left = 0
// mid = 1
// right = 2