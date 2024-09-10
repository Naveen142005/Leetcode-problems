class Solution {
public:
    string phone[10] = {\\,\\,\abc\,\def\,\ghi\,\jkl\,\mno\,\pqrs\,\tuv\,\wxyz\};
    vector<string> res;
    void solve(string digits ,string ans,int k){
        if (digits.size() == k) {
             res.push_back(ans);
             return;
        }
        for (int i = 0 ; i < phone[(digits[k]) - '0'].size() ; i++)
            solve(digits,ans + phone[(digits[k]) - '0'][i],k+1);
        
    }
    vector<string> letterCombinations(string digits) {
        ios_base::sync_with_stdio(false);
        if (!digits.size())return {};
        res.clear();
        solve(digits,\\,0);
        return res;
    }
};