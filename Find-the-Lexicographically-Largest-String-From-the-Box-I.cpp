class Solution {
public:
    string answerString(string word, int numFriends) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if (numFriends == 1) return word; 
        int ss = word.size();
        int sz = ss - numFriends + 1;
        string s = "";
        string t = "";
        for (int i = 0 ; i < ss ; i += 1) {
             s = word.substr (i , sz);
             if (s > t) t = s;
        }
        return t;
    }
};