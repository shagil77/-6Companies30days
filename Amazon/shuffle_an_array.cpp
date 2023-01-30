#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> arr;
    int n;
public:
    Solution(vector<int>& nums) {
        n = nums.size();
        arr = nums;
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled(n, INT_MIN);
        for(int i=1; i<=n; i++) {
            int idx = rand()%n;
            while(shuffled[idx]!=INT_MIN) idx = rand()%n;
            shuffled[idx] = arr[i-1];
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {

    
    return 0;
}