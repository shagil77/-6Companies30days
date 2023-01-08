#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if(n<3) return 0;
        int ans = 0;

        // n.n-1/2
        for(int i=0; i<n; i++) {
            unordered_map<ll, int> cnt;
            for(int j=0; j<n; j++) {
                if(j!=i) {
                    ll d = (points[i][0]-points[j][0])*(points[i][0]-points[j][0]) + (points[i][1]-points[j][1])*(points[i][1]-points[j][1]);

                    cnt[d]++;
                }
            }

            for(auto [d,c]:cnt) {
                int cn = (c*(c-1));
                ans+=cn;
            }
        }

        return ans;
    }
};

int main()
{


    return 0;
}