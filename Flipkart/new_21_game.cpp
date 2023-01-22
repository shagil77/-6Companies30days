#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || n>=k+maxPts) return 1.0;

        vector<double> dp(n+1, 0.0);
        dp[0] = 1.0;
        double runningSum = 1.0, result = 0.0;

        for(int i=1; i<=n; i++) {
            dp[i] = runningSum/(double)maxPts;

            // dp[i] = (dp[i-1] + dp[i-2] + .... + dp[i-maxPts]).C
            // dp[i+1] = (dp[i] + dp[i-1] + dp[i-2] + .... + dp[i+1-maxPts]).C

            // handling the front addition of dp[i]
            if(i<k) runningSum += dp[i];
            else result += dp[i];

            // handling the back subtraction of dp[i-maxPts]
            if(i-maxPts>=0) runningSum -= dp[i-maxPts];
        }

        return result;
    }
};

int main() {

    
    return 0;
}