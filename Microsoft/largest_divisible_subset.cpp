#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int lastIdx = 0, mx=0;
        for(int i=0; i<n; i++) hash[i]=i;
        for(int idx=0; idx<n; idx++) {
            for(int prevIdx=0; prevIdx<idx; prevIdx++){
                if(nums[idx]%nums[prevIdx]==0 && dp[idx]<dp[prevIdx]+1) {
                    dp[idx] = 1+dp[prevIdx];
                    hash[idx] = prevIdx;
                }
            }
            if(dp[idx]>mx) {
                mx = dp[idx];
                lastIdx = idx;
            }
        }

        vector<int> lis;
        lis.push_back(nums[lastIdx]);
        while(hash[lastIdx]!=lastIdx) {
            lis.push_back(nums[hash[lastIdx]]);
            lastIdx = hash[lastIdx];
        }
        reverse(lis.begin(), lis.end());
        return lis;
    }
};

int main()
{


    return 0;
}