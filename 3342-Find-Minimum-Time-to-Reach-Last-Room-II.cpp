#define VII vector<pair<int,int>>
#define II pair<int,int>
#define PP vector<int>
#define VPP vector<pair<int, pair<int,int>>>

#define f first
#define s second

class Solution {
public:
    int dir[4][2] = { {0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue <PP , vector<PP> , greater<PP> > pq;

        int m = moveTime.size() , n = moveTime[0].size();

        vector<vector<int>> dict (m , vector<int> (n , INT_MAX));

        pq.push({0,0,0,1});
        dict[0][0] = moveTime[0][0];
        bool f = true;
        while (pq.size()) {
            int ss = pq.size();
            while (ss--) {
                PP p = pq.top();
                int w = p[0];
                int x = p[1];
                int y = p[2];
                int plus = (p[3] == 1 ? 2 : 1);


                pq.pop();

                for (int i = 0 ; i < 4 ; i += 1) {
                    int u = x + dir[i][0];
                    int v = y + dir[i][1];
                    if (u >= 0 && v >= 0 && u < m && v < n){
                        if (p[3] + max (w , moveTime[u][v]) < dict[u][v]) {
                            dict[u][v] = p[3] + max (w , moveTime[u][v]);
                            pq.push({dict[u][v] ,u,v , plus});
                        }
                    }
                }
            }
            // f = !f;
        }
       return dict[m - 1][n - 1];
    }
};