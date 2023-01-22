#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int m, n;
    int bfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if(vis[x][y] || grid[x][y]==0) return 0;
        vis[x][y]=true;
        int ans = 1;

        for(int i=0; i<4; i++) {
            int xx = x+dir[i].first, yy = y+dir[i].second;
            if(0<=xx && xx<m && 0<=yy && yy<n && !vis[xx][yy] && grid[xx][yy]==1) {
                ans += bfs(xx,yy,grid,vis);
            }
        }

        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j]) {
                    ans = max(ans, bfs(i,j,grid,vis));
                }
            }
        }

        return ans;
    }
};

int main() {

    
    return 0;
}