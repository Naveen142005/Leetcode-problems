class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        ios_base::sync_with_stdio(false);
        vector<int> minutes;

        for (auto i : timePoints)
             minutes.push_back((stoi(i.substr(0, 2))*60) + (stoi(i.substr(3, 5))));
        

        sort(minutes.begin(),minutes.end());

        int s = minutes.size() , ans = 1440 - minutes[s-1] + minutes[0];

        for (int i = 0 ; i < s - 1 ; i++) 
            ans = min (ans, abs(minutes[i] - minutes[i + 1]));

        return ans;
    }
};