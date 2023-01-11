#include<bits/stdc++.h>
using namespace std;

class Solution {
    int m = (int)1e9+7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long ans = 0;
        long numSharing = 0;
        vector<long> dp(n+1, 0);
        dp[1] = 1;
        // noOfPeopleSharing = noOfPeopleSharing + noOfNewPeopleSharing - noOfPeopleForgetting
        for(int i=1+delay; i<=n; i++) {
            long newSharing = 0, forgetting = 0;
            if(i-delay>=1) newSharing = dp[i-delay];
            if(i-forget>=1) forgetting = dp[i-forget];

            numSharing += (newSharing - forgetting + m) % m;

            dp[i] = numSharing;
        }

        for(int i=n-forget+1; i<=n; i++) ans = (ans+dp[i])%m;

        return ans;
    }
};

int main()
{


    return 0;
}