#include<bits/stdc++.h>
using namespace std;

#define pis pair<int, string>
bool comparePairs(pis i1, pis i2)
{
    if(i1.first==i2.first) return i1.second<i2.second;
    return (i1.first > i2.first);
}
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        unordered_map<string, vector<pis>> vids;
        unordered_map<string, long long int> totViews;
        for(int i=0; i<n; i++) {
            vids[creators[i]].push_back({views[i], ids[i]});
            totViews[creators[i]]+=views[i];
        }

        long long int mx = INT_MIN;
        for(auto [creator, view]:totViews) {
            mx = (mx<view)?view:mx;
        }

        vector<vector<string>> ans;
        for(auto [creator, view]:totViews) {
            if(mx==view) {
                sort(vids[creator].begin(), vids[creator].end(), comparePairs);
                ans.push_back({creator, vids[creator][0].second});
            }
        }

        return ans;
        
    }
};

int main() {

    
    return 0;
}