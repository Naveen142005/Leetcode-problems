class Solution {
public:
    string smallestPalindrome(string s) {
        int fq[26] = {0};
        for (auto i : s ) fq[i - 'a'] += 1;
        string fi , mi , li;
        fi = mi = li = "";
        for (int i = 0 ; i  < 26 ; i += 1) {
        string f = "" , m = "", l ="";
            if (fq[i]) {
                if (fq[i] & 1) {
                    for (int j = 0 ; j < (fq[i] / 2) ; j += 1) {
                        f += (i + 'a');
                    }
                    m += (i + 'a');

                    fi += f;
                    mi += m;
                }
                else {
                    for (int j = 0 ; j < (fq[i] / 2) ; j += 1) {
                        f += (i + 'a');
                    }
                    fi += f;
                }
            }
        }
        string ans = "";
        ans += fi;
        ans += mi;
        for (int i = fi.size()-  1 ; i >= 0 ; i -= 1) {
            ans += fi[i];
        }
        return ans;
    }
};