#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> maxIdx;
    vector<int> v;
    int maxSum;
    int leftArrows;
    void solve(int i, int numArrows, int sum, vector<int>& aliceArrows) {
        if(i==12 || numArrows==0) {
            if(sum>maxSum) {
                maxIdx = v;
                maxSum = sum;
                leftArrows = numArrows;
            }
            return;
        }

        if(numArrows-aliceArrows[i]-1>=0) {
            v.push_back(i);
            solve(i+1, numArrows-aliceArrows[i]-1, sum+i, aliceArrows);
            v.pop_back();
        }

        solve(i+1, numArrows, sum, aliceArrows);
    }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        maxSum = INT_MIN;
        vector<int> ans(12, 0);
        solve(0, numArrows, 0, aliceArrows);

        for(auto idx:maxIdx) ans[idx] = aliceArrows[idx]+1;
        ans[0]+=leftArrows;

        return ans;
    }
};

int main()
{


    return 0;
}