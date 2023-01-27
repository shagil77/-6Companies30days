#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<long long> hashes;
    vector<long long> powers;
    const int p = 31;
    const int m = (int)1e9+7;

    void preProcessing(string &text) {
        int n = text.length();
        hashes.resize(n+1);
        powers.resize(n+1);
        powers[0]=1;

        for(int i=1; i<=n; i++) {
            hashes[i] = (hashes[i-1]*p + text[i-1])%m;
            powers[i] = (powers[i-1]*p)%m;
        }
    }

    int getHash(int l, int r) {
        return (hashes[r]+m-hashes[l]*powers[r-l]%m)%m;
    }
public:
    // Using String Hash (Rolling Hash)
    int distinctEchoSubstrings(string text) {
        preProcessing(text);
        int n = text.length();
        unordered_map<int,int> mp;
        int ans=0;

        for(int len=1;len<=n/2;len++) {
            int count=0;
            for(int l=0,r=len;l<n-len;l++,r++) {
                if(text[l]==text[r]) count++;
                else count=0;

                if(count==len) {
                    int hash = getHash(l-len+1, l+1);
                    if(mp[hash]==0) {
                        mp[hash]++;
                        ans++;
                    }
                    count--;
                }
            }
        }

        return ans;
    }
};

int main() {

    
    return 0;
}