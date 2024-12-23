class Solution {
public:
    int fun (char s) {
        switch (s) {
            case 'a': return 1;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default : return 0;
        }
    }
    int maxVowels(string s, int k) {
        int ss = s.size();
        if (ss == k) return ss; 
        
        int cnt = 0;
        for (int i = 0 ; i < k ; i += 1) if (fun(s[i])) cnt += 1;

        int i = 0 , j = k - 1;
        int mx = cnt;
        while (j < ss) {
            if (fun(s[i])) cnt -= 1;
            // mx = max (cnt , mx);
            i += 1, j += 1;
            if (fun(s[j])) cnt += 1;
            mx = max (cnt , mx);
        }
        return mx;
    }
};