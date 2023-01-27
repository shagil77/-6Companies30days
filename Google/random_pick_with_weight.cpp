#include<bits/stdc++.h>
using namespace std;

class Solution {
    int sum, n;
    vector<int> preSum;
public:
    Solution(vector<int>& w) {
        sum=accumulate(w.begin(),w.end(),0);
        n=w.size();
        preSum.resize(n,0);
        preSum[0]=w[0];

        for(int i=1;i<n;i++) {
            preSum[i]=preSum[i-1]+w[i];
        }
    }
    
    int pickIndex() {
        int idx = rand()%preSum[n-1];
        
        auto it = upper_bound(preSum.begin(), preSum.end(), idx);
        return it-preSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main() {

    
    return 0;
}