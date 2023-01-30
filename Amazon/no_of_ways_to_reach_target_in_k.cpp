#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001] = {}, mod = (int)1e9+7;
class Solution {
    int solve(int k, int d) {
        if(d>k) return 0;
        if(d==k) return 1;

        // checking if solve(k,d) has been called on a previous testcase
        // by checking the value of static dp array
        if(dp[k][d]==0) { 
            dp[k][d] = (1+solve(k-1, d+1)+solve(k-1, abs(d-1)))%mod;
        }
        return dp[k][d]-1;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        return solve(k, abs(startPos-endPos));
    }
};

int main() {

    
    return 0;
}