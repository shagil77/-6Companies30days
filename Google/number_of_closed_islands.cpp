#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis, bool& isCorrect) {
        if(grid[row][col] == 1) return;
        if(row==0 || row==grid.size()-1 || col==0 || col==grid[0].size()-1) isCorrect = false;
        vis[row][col]=true;

        for(int i=0; i<4; i++) {
            int xx = row+dir[i].first, yy = col+dir[i].second;
            if(xx<0 || xx>=grid.size() || yy<0 || yy>=grid[0].size()) continue;
            if(!vis[xx][yy]) {
                dfs(xx, yy, grid, vis, isCorrect);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,0));

        int ans = 0;

        for(int i=1; i<m-1; i++) {
            for(int j=1; j<n-1; j++) {
                if(!vis[i][j] && grid[i][j]==0) {
                    bool res = true;
                    dfs(i,j,grid,vis,res);
                    if(res) ans++;
                }
            }
        }

        return ans;
    }
};

int main() {

    
    return 0;
}