#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<long long int>> preSum;
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        preSum.resize(m, vector<long long int>(n, 0));
        preSum[0][0] = grid[0][0];

        for(int i=1; i<m; i++) preSum[i][0] = preSum[i-1][0]+(long long int)grid[i][0];
        for(int j=1; j<n; j++) preSum[0][j] = preSum[0][j-1]+(long long int)grid[0][j];

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                preSum[i][j] = preSum[i][j-1]+preSum[i-1][j]-preSum[i-1][j-1]+(long long int)grid[i][j];
            }
        }

        long long int ans = 0;
        for(int i=2; i<m; i++) {
            for(int j=2; j<n; j++) {
                long long int m1=0, m2=0, m3=0;
                if(i-3>=0) m1 = preSum[i-3][j];
                if(j-3>=0) m2 = preSum[i][j-3];
                if(i-3>=0 && j-3>=0) m3 = preSum[i-3][j-3];

                int sum = preSum[i][j]-(m1+m2-m3+grid[i-1][j]+(long long int)grid[i-1][j-2]);
                ans = (sum>ans)?sum:ans;
            }
        }

        return ans;
    }
};

int main() {

    
    return 0;
}