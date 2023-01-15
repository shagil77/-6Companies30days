#include<bits/stdc++.h>
using namespace std;

#define pss pair<string,string>
#define psi pair<string, int>

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int l = nums[0].size();
        int n = nums.size();

        vector<int> res;
        for(auto query:queries) { // index of kth smallest, last 'trim' digits
            int k = query[0], trim = query[1];
            vector<psi> v;
            for(int i=0; i<nums.size(); i++) {
                v.push_back({nums[i].substr(l-trim), i});
            }
            sort(v.begin(), v.end());
            res.push_back(v[k-1].second);
        }

        return res;
    }
};

int main()
{


    return 0;
}