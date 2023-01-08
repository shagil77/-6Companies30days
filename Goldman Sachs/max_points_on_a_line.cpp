#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1) return 1;

        int ans = 2;

        for(int i=0; i<n; i++) {
            unordered_map<double, int> mp;
            for(int j=0; j<n; j++) {
                if(j!=i) {
                    int dy = points[j][1]-points[i][1], dx = points[j][0]-points[i][0];
                    mp[atan2(dy,dx)]++;
                } 
            }
            for(auto [a,c]:mp) ans = max(ans, c+1);
        }

        return ans;
    }
};

int main()
{


    return 0;
}