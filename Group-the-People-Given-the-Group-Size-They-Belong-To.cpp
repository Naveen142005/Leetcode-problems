class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        int ss = nums.size();
        vector<vector<int>> arr(ss + 1) , ans;

        for (int i = 0 ; i < ss ; i += 1)
            arr[nums[i]].push_back (i);
        
        for (int i = 0 ; i < ss + 1 ; i += 1) {
            int p = i;
            vector<int>  tt;
            int t = 0;
            while (t < arr[i].size()) {
               
                tt.push_back(arr[i][t]);
                t += 1;
                if (!(t % p)) {
                    ans.push_back(tt);
                    tt.clear();
                }
            }
        }
        return ans;
    }
};