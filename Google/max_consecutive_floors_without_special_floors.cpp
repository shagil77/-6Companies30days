#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int low = bottom, high = special[0];
        int maxRange = high-low, n = special.size();

        for(int i=1; i<n; i++) {
            maxRange = max(maxRange, special[i]-high-1);
            low = high;
            high = special[i];
        }

        maxRange = max(maxRange, top-high);

        return maxRange;
    }
};

int main() {

    
    return 0;
}