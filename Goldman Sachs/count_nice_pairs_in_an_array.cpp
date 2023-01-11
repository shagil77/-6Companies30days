#include<bits/stdc++.h>
using namespace std;

class Solution {
    int m = (int)1e9 + 7;
    int rev(string s) {
        reverse(s.begin(), s.end());
        return stoi(s);
    }
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,long> diffCount;

        for(int i=0; i<n; i++) {
            diffCount[nums[i]-rev(to_string(nums[i]))]++;
        }

        long ans = 0;
        for(auto &[diff,count]:diffCount) {
            ans=(ans + (count*(count-1))/2)%m;
        }

        return ans;


    }
};

int main()
{


    return 0;
}