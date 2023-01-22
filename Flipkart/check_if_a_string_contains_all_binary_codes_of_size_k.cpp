#include<bits/stdc++.h>
using namespace std;

class Solution {
    int binToDec(string bin) {
        int n = bin.length();
        int ans=0;

        for(int i=0; i<n; i++) {
            if(bin[i]=='1') ans+=(int)pow(2,n-i-1);
        }

        return ans;
    }
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_map<int, int> mp;
        int lim = (int)pow(2,k);

        int i=0, j=0, count=0;
        string str = "";
        while(j<n) {
            str += s[j];

            if(str.length()==k) {
                int decNum = binToDec(str);
                if(mp[decNum]==0) mp[decNum]++;

                str.erase(0,1);
            }

            j++;
        }

        if(mp.size()==lim) return true;
        
        return false;
    }
};

int main() {

    
    return 0;
}