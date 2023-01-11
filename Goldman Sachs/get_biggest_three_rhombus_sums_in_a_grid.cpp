#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<vector<int>> ld = grid, rd = grid;
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int prevI = i-1;
                int prevJ = j-1;
                if(prevI>=0 && prevJ>=0) ld[i][j]+=ld[prevI][prevJ];
                prevJ=j+1;
                if(prevI>=0 && prevJ<n) rd[i][j]+=rd[prevI][prevJ];
            }
        }

        map<int,int> mp;

         for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                mp[grid[i][j]]++;
                for(int k=1; k<=max(m,n); k++) {
                    int left = j-k;
                    int right = j+k;
                    int bottom = i+2*k;
                    if(left < 0 || right >= n || bottom >= m) continue;

                    int sum = ld[i+k][right]-ld[i][j]
                                + ld[bottom][j]-ld[i+k][left]
                                + rd[i+k][left]-rd[i][j]
                                + rd[bottom][j]-rd[i+k][right]
                                + grid[i][j]-grid[bottom][j];

                    mp[sum]++;
                }

                while(mp.size()>3) {
                    auto it = mp.begin();
                    mp.erase(it);
                }
            }
        }

        vector<int> ans;
        for(auto it=mp.rbegin(); it!=mp.rend(); it++) {
            ans.push_back(it->first);
            if(ans.size()>=3) return ans;
        }

        return ans;
    }
};

int main()
{


    return 0;
}