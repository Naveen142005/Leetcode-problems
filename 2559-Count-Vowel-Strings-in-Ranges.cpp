class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        ios_base::sync_with_stdio(false);
        
        int ss = words.size() , cnt , qq = q.size() , index = 0;
        vector<int> arr (ss , 0) , ans (qq);
        
        for (int i = 0 ; i < ss ; i += 1 , cnt = 0) {
            if (isVowel(words[i][0]) and isVowel(words[i][words[i].size() - 1])) cnt = 1;
            arr[i] = i ? arr[i - 1] +  cnt :  cnt;
        } 

        for (auto& qe : q) 
             ans [index++] = qe[0] ?  arr[qe[1]] - arr[qe[0] - 1] : arr[qe[1]];
        return ans;

    }
};