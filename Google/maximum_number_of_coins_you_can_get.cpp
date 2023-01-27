#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end(), greater<int>());

        int l = 1, r = n-1;
        int ans = 0;
        while(l<r) {
            ans+=piles[l];
            l+=2;
            r--;
        }

        return ans;
    }
};

int main() {

    
    return 0;
}