#define frist f
#define second s

class Solution {
public:
    vector <int> val;
    vector <bool> visited;
    int n , ss;
    
    int snakesAndLadders(vector<vector<int>>& board) {
         ss = board.size();
         n = (ss* ss);
        val.resize (n + 1 , -1);
        visited.resize(n + 1, false);
        vector <int> dict (n + 1 , INT_MAX);
        bool f = true;
        int cnt = 1;
        for (int i = ss - 1 ; i >= 0 ; i -= 1) {
            if (f) {
                for (int j = 0 ; j < ss ; j += 1) {
                    val[cnt++] = board[i][j];
                }
            }
            else {
                for (int j = ss - 1 ; j >= 0 ; j -= 1) {
                    val[cnt++] = board[i][j];
                }
            }
            f = !f;
        }

        
       priority_queue <pair <int, int> , vector<pair <int ,int>> , greater<> > q;
        q.push ({0 , 1});
        visited[1] = true;
        dict [1] = 0;
        while (q.size()) {
            auto [cnt , idx] = q.top();
            q.pop();
            visited[idx] = true;
            for (int i = 1 ; i <= 6 ; i += 1) {
                int id = min (idx + i , n);
                int sent = val[id] != -1 ? val[id] : id;
                if (visited[sent]) continue;
                if (cnt + 1 < dict[sent]) {
                    dict [sent] = cnt + 1;
                    q.push({dict[sent] , sent});
                }
            }
        }
        return dict[n] == INT_MAX ? -1 : dict[n];
    }
};