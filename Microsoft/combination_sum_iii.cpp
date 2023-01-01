#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> v;
    void solve(int k, int i, int n, int sum) {
        if(k==0 && sum==n) {
            ans.push_back(v);
            return;
        } 
        if(i>9) return;

        if(sum+i<=n) {
            v.push_back(i);
            solve(k-1, i+1, n, sum+i);
            v.pop_back();
            solve(k, i+1, n, sum);
        } else {
            solve(k, i+1, n, sum);
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k, 1, n, 0);
        return ans;
    }
};

int main()
{


    return 0;
}