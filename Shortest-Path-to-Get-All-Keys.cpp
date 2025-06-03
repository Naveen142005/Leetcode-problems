int dir[4][2] = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
class Solution {
public:
    int shortestPathAllKeys(vector<string>& s) {
        using t = tuple <int , int , int , int>;
        priority_queue <t , vector<t> , greater<>> q;
        int m = s.size(); 
        int n = s[0].size();
      
    
        int keys = 0;
        int st , end;
        for (int i = 0 ; i < m ; i += 1) {
            for (int j = 0 ; j < n ; j += 1) {
                if (s[i][j] == '@') st = i , end = j;
                else if (islower(s[i][j])) {
                    s[i][j] = (char)((s[i][j] - 'a') + '0');
                    keys += 1;
                }
            }
        }
        
        int fullbit = (1 << keys) - 1;
        vector<vector<vector<int>>> dict (m , vector<vector<int>> (n ,vector<int>(fullbit + 1 , INT_MAX)));
        set <tuple <int, int , int>> visi;
        q.push ({0 , st , end  , 0});

        while (q.size()) {
            auto [cnt , idx , jdx  , mask] = q.top();
            q.pop();

            if (mask == fullbit) return cnt - 1;
        
            

            if (visi.find ({idx , jdx , mask}) != visi.end()) continue;
            visi.insert ({idx , jdx , mask});

            if (isdigit(s[idx][jdx])) {
                mask |= (1 << (s[idx][jdx] - '0'));
            }
            
            else if (isalpha (s[idx][jdx])) {
                int d = (s[idx][jdx] - 'A');
                if (mask & (1 << d));
                else continue;
            }
            else if (s[idx][jdx] == '#') continue;

            for (int i = 0 ; i < 4 ; i += 1) {
                int ni = idx + dir[i][0];
                int nj = jdx + dir[i][1];

                if (ni >= 0 && nj >= 0 && ni < m && nj < n) 
                    q.push ({1 + cnt , ni , nj , mask});
            }

        }
        return -1;
    }
};