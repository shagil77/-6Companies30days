#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        set<vector<int>> st;
        
        for(int i=0; i<n; i++) {
            vector<int> v;
            int c=0;
            for(int j=i; j<n; j++) {
                v.push_back(nums[j]);
                if(nums[j]%p==0) c++;

                if(c>k) break;
                st.insert(v);
            }
        }

        return st.size();
    }
};

int main() {

    
    return 0;
}