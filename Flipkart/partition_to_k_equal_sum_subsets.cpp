#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<bool> vis;
    int subset_sum;
    bool backtrack(vector<int>& nums, int idx, int k, int sum) {
        if(k==0) return true;
        if(sum==subset_sum) {
            return backtrack(nums, 0, k-1, 0);
        }

        for(int i=idx; i<nums.size(); i++) {
            if(vis[i] || nums[i]+sum>subset_sum) continue;

            vis[i] = true;
            if(backtrack(nums, i+1, k, sum+nums[i])) return true;
            vis[i] = false;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxElem = *max_element(nums.begin(), nums.end());
        if(sum%k!=0) return false;

        subset_sum = sum/k;
        if(maxElem>subset_sum) return false;

        sort(nums.rbegin(), nums.rend()); // descending order sorting
        vis.resize(nums.size(), false);
        

        return backtrack(nums, 0, k, 0);
    }
};

int main() {

    
    return 0;
}