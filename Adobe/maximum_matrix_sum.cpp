#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll sum = 0, count = 0;
        int mn = INT_MAX;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]<0) {
                    count++;
                }
                mn = min(mn, abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }

        if(count%2==0) return sum;
        return (sum-2*mn);
    }
};

int main()
{


    return 0;
}