#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int res = 0, ans = INT_MIN;

        while(r<2*n) {
            if(r<n) {
                res+=r*nums[r];
                r++;
            } else {
                ans = max(ans, res);
                res = res - (sum-nums[l]) + nums[l]*(n-1);
                ans = max(ans, res);
                l++;
                r++;
            }
        }
        
        return ans;
    }
};

int main()
{


    return 0;
}