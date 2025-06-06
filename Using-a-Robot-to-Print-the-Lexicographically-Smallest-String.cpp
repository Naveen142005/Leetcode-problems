class Solution {
public:
    string robotWithString(string s) {
        int ss = s.size();
        int fq[26] = {0} , k;
        
        for (int i = 0 ; i < ss ; i += 1){
            fq[s[i] - 'a'] += 1;
        }   
        stack <char> stk;
        string ans = "";
        for (int i = 0 ; i < ss ; i += 1){
            stk.push(s[i]);
            fq[s[i] - 'a'] -= 1;
            bool f = true;
            while (stk.size() && f) {
                int ch = stk.top() - 'a' ;
                for ( k = 0 ; k != ch ; k +=1 ) {
                    if (fq[k]) break;
                }

                
                if (k == ch) {
                    ans += stk.top();
                    // fq[stk.top() - 'a'] -= 1;
                    stk.pop();
                }
                else f = false;
            }
        }
        while (stk.size()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};