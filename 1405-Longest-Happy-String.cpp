 static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string f,s,t;
        int fc,sc,tc;   

        vector<pair<int,string>> p = {{a,"a"} , {b,"b"} , {c,"c"}};
        sort(p.begin() , p.end());

        f = p[2].second , s = p[1].second , t = p[0].second;
        fc = p[2].first , sc = p[1].first , tc = p[0].first;

        vector<string> answers;

        while (fc > 0) {
            if (fc > 1) {
                answers.push_back((f+f));
                fc -= 2;
            }
            if (fc == 1) {
                answers.push_back(f);
                fc--;
            }
        }
        int i = 0;
        int _size = (answers.size());

        while (sc > 0) {
            answers[i] = answers[i] +s;
            sc--;
            i = (i + 1) % _size;
        }
        while (tc > 0) {
            answers[i] = answers[i] + t;
            tc--;
            i = (i + 1) % _size;
        }
        string ans ="" , _g="";
        for (auto& i : answers) 
           ans += i;

        for (int i = 0 ; i <= ans.size() - 3; i++) {
            if (ans[i] == ans[i+1] && ans[i+1]== ans[i+2]) {
                for (int j = 0; j < i + 2 ; j++) {
                    _g += ans[j];
                }
                return _g;
            }
        }
        return ans;
    }
}; 