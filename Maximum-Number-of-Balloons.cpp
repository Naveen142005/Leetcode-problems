1class Solution {
2public:
3    int maxNumberOfBalloons(string text) {
4        int fq[26] = {0};
5
6        string temp = "balloon";
7        int ans = INT_MAX;
8
9        for (auto& i: text)
10            fq[i - 'a'] += 1;
11        
12
13        fq['l' - 'a'] /= 2;
14        fq['o' - 'a'] /= 2;
15
16        for (auto& i: temp) 
17            ans = min(ans, fq[i - 'a']);
18    
19        return ans;
20    }
21};