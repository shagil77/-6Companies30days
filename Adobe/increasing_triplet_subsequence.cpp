#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
class Solution {
    
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<pii> minElem(n), maxElem(n);
        minElem[0] = {nums[0],0};
        maxElem[n-1] = {nums[n-1], n-1};
        for(int i=1; i<n-1; i++) {
            if(nums[i]<minElem[i-1].first) minElem[i]={nums[i],i};
            else minElem[i]=minElem[i-1];

            if(nums[n-i-1]>maxElem[n-i].first) maxElem[n-i-1]={nums[n-i-1], n-i-1};
            else maxElem[n-i-1]=maxElem[n-i];
        }

        for(int i=1; i<n-1; i++) {
            if(minElem[i].first<nums[i] && nums[i]<maxElem[i].first) {
                return true;
            }
        }

        return false;
    }
};

int main()
{


    return 0;
}