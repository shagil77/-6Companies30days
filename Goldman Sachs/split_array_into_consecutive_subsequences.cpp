#include<bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> amp, vmp;
        for(auto num:nums) amp[num]++;

        for(auto num:nums) {
            if(amp[num]==0) continue;
            else if(vmp[num]!=0) {
                amp[num]--;
                vmp[num]--;

                vmp[num+1]++;
            } else if(amp[num]>0 && amp[num+1]>0 && amp[num+2]>0) {
                amp[num]--;
                amp[num+1]--;
                amp[num+2]--;

                vmp[num+3]++;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main()
{


    return 0;
}