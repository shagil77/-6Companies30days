#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        if(n<2) return -1;

        unordered_map<int,int> mp;
        int i=0, j=0;
        int ans = INT_MAX;
        while(i<=j && j<n) {
            if(mp[cards[j]]!=0) {
                ans = min(ans, j-i+1);
                mp[cards[i]]--;
                i++;
            } else {
                mp[cards[j]]++;
                j++;
            }
        }

        if(ans==INT_MAX) return -1;
        return ans;
    }
};

int main()
{


    return 0;
}