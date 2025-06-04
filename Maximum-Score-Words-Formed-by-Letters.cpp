class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int ss = words.size();
        int end = (1 << ss);
        int mx = 0;
        int fq[26] = {0} , temp[26] = {0};

        for (char i : letters) fq[i - 'a'] += 1 , temp[i - 'a'] += 1;

        for (int i = 0 ; i < end ; i += 1) {
            int sum = 0;
            for (int j = 0 ; j < ss ; j += 1) {
                int t = 0;
                if ((1 << j) & i) {
                    for (auto k : words[j]) {
                        if (fq[k - 'a']) {
                            t += score[k - 'a'];
                            fq[k - 'a'] -= 1;
                        }
                        else {
                            t = 0;
                            break;
                        }
                    }
                    sum += t;
                }
            }
            mx = max (sum , mx);
            for (int i = 0 ; i < 26 ; i += 1) {
                fq[i] = temp[i];
            }
        }
        return mx;
    }
};