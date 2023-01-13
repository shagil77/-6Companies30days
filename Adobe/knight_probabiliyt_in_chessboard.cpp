#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> x = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> y = { 1, -1,  2, -2, 2,-2, 1,-1};
    vector<vector<vector<double>>> dp;

    double solve(int n, int k, int row, int column) {
        if(k==0) return 1.0;
        if(dp[row][column][k]!=-1) return dp[row][column][k];
        double count = 0.0;

        for(int i=0; i<8; i++) {
            int xx = row+x[i], yy = column+y[i];
            
            if(0<=xx && xx<n && 0<=yy && yy<n) {
                // count++;
                // prob*=knightProbability(n,k-1,xx,yy);
                count+=solve(n,k-1,xx,yy);
            }
        }

        double ans = count/8.0;
        dp[row][column][k]=ans;

        return ans;
    } 
public:
    double knightProbability(int n, int k, int row, int column) {
        dp.resize(n+1, vector<vector<double>>(n+1, vector<double>(k+1, -1)));
        return solve(n,k,row,column);
    }
};

int main()
{


    return 0;
}