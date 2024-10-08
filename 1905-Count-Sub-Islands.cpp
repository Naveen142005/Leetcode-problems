class Solution {
    bool dfs(vector<vector<int>>& grid2,int i,int j,int m,int n,vector<vector<int>>& grid1){
        stack<pair<int,int>> stk;
        stk.push({i,j});
        bool b = true;
        while(!stk.empty()){
            pair<int,int> t = stk.top();
            if(!grid1[t.first][t.second]) b = false;
            stk.pop();
            if(t.first-1 >=0 && grid2[t.first-1][t.second]){
                grid2[t.first-1][t.second] = 0;
                stk.push({t.first-1,t.second});
            }
            if(t.second-1 >=0 && grid2[t.first][t.second-1]){
                grid2[t.first][t.second-1] = 0;
                stk.push({t.first,t.second-1});
            }
            if(t.second+1 < n && grid2[t.first][t.second+1]){
                grid2[t.first][t.second+1] = 0;
                stk.push({t.first,t.second+1});
            }
            if(t.first+1 < m && grid2[t.first+1][t.second]){
                grid2[t.first+1][t.second] = 0;
                stk.push({t.first+1,t.second});
            }  
        }
        return b;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        int res = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid2[i][j]){
                    if(dfs(grid2,i,j,m,n,grid1)) res++; 
                }
                    
            }
        }
        return res;
    }
};