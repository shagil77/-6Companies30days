#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX, mx = INT_MIN;
        int flag = false;
        for(int i=1; i<n; i++) {
            if(nums[i]<nums[i-1]) flag = true;
            if(flag) mn = min(mn, nums[i]);
        }

        flag = false;

        for(int i=n-2; i>=0; i--) {
            if(nums[i]>nums[i+1]) flag = true;
            if(flag) mx = max(mx, nums[i]);
        }

        int start, end;
        for(start=0; start<n; start++) {
            if(mn<nums[start]) break;
        }

        for(end=n-1; end>=0; end--) {
            if(mx>nums[end]) break;
        }

        return ((end-start)<0)?0:(end-start+1);
    }
};

int main()
{


    return 0;
}