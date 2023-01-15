#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
class Solution {
    // vector<pii> move = {{1,0}, {0,1}};
    // int ans = INT_MIN, m, n;
    // vector<int> v;

    // Method 1 (Backtracking)
    // void solve(int row, int col, int sum, vector<vector<int>>& dungeon) {
    //     if(ans>=0) return;

    //     sum+=dungeon[row][col];
    //     v.push_back(dungeon[row][col]);

    //     if(row==m-1 && col==n-1) {
    //         int s=0, mn = INT_MAX;
    //         for(auto it:v) {
    //             s+=it;
    //             mn = min(mn,s);
    //         }
    //         ans = max(ans, mn);
    //         return;
    //     }

    //     for(int i=0; i<2; i++) {
    //         int xx = row+move[i].first, yy = col+move[i].second;
    //         if(0<=xx && xx<m && 0<=yy && yy<n) {
    //             solve(xx, yy, sum, dungeon);
    //             v.pop_back();
    //         }
    //     }
    // }

    // Method 2(Memoization)
    int getVal(vector<vector<int>> &mat, vector<vector<int>> &dp , int i=0, int j=0)
    {
        int n = mat.size();
        int m = mat[0].size();    
        
        if(i == n || j == m)    return 1e9; 
        
        if(i == n-1 and j == m-1)
            return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;
        
        /// if we know the answer for this cell then no need to recalculate those, simply return those values 
        if( dp[i][j] != 1e9)
            return dp[i][j];
        
        int IfWeGoRight = getVal(mat , dp , i , j+1);
        int IfWeGoDown = getVal(mat , dp , i+1 , j);
        
        int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) -mat[i][j];
        
        /// before returning the values, we must store the answers for this cell which we hacve calculated
        /// in next recurssive call this value will be used to save some computation, aka repetative work which we are doing.
        dp[i][j] = ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;      
        return dp[i][j];
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        // solve(0,0,0,dungeon);

        // if(ans>0) return 1;
        // return abs(ans)+1;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 1e9));

        return getVal(dungeon, dp);
    }
};

int main()
{


    return 0;
}