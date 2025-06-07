using t = pair <char , int>;
class Solution {
public:

    struct cmp{            
        bool operator()(t& a , t& b) {
             if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    string clearStars(string s) {
        priority_queue <t, vector<t> , cmp> pq;
        string ans = "";
        int ss = s.size();
        for (int i = 0 ; i < ss ; i += 1) {
            if (s[i] != '*') pq.push({s[i] , i});
            else {
                s[pq.top().second] = '*';
                pq.pop();
            }
        }
        
        for (int i = 0 ; i < ss ; i += 1) {
            if (s[i] != '*') ans += s[i];
        }
        return ans;
    }
};