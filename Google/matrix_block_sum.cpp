#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> preSum(m, vector<int>(n, 0));
        vector<vector<int>> answer(m, vector<int>(n, 0));

        preSum[0][0] = mat[0][0];

        for(int i=1; i<m; i++) {
            preSum[i][0]=preSum[i-1][0]+mat[i][0];
        }

        for(int j=1; j<n; j++) {
            preSum[0][j]=preSum[0][j-1]+mat[0][j];
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                preSum[i][j] = preSum[i][j-1]+preSum[i-1][j]-preSum[i-1][j-1]+mat[i][j];
            }
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                preSum[i][j] = preSum[i][j-1]+preSum[i-1][j]-preSum[i-1][j-1]+mat[i][j];
            }
        }



        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int m1=0, m2=0, m3=0;
                int x = min(i+k, m-1), y = min(j+k, n-1);

                if(j-k-1>=0) m1 = preSum[x][j-k-1];
                if(i-k-1>=0) m2 = preSum[i-k-1][y];
                if(i-k-1>=0 && j-k-1>=0) m3 = preSum[i-k-1][j-k-1];
                
                answer[i][j] = preSum[x][y] - (m1+m2-m3);
            }
        }

        return answer;
    }
};

int main() {

    
    return 0;
}