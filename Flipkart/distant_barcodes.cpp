#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size(), i=0;
        vector<int> ans(n,-1);
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;

        for(auto barcode:barcodes) mp[barcode]++;

        for(auto [barcode,count]:mp) pq.push({count, barcode});

        while(!pq.empty()) {
            auto [count, barcode] = pq.top();
            pq.pop();

            while(count>0) {
                ans[i]=barcode;
                i+=2;
                if(i>=n) i=1;
                count--;
            }
        }

        return ans;
    }
};

int main() {

    
    return 0;
}