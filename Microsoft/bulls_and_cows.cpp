#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char,int> mp;
        int n = secret.length();
        for(int i=0; i<n; i++) {
            if(secret[i]==guess[i]) bulls++;
            mp[secret[i]]++;
        }

        for(int i=0; i<n; i++) {
            if(mp[guess[i]]>0) {
                cows++;
                mp[guess[i]]--;
            }
        }

        string ans = to_string(bulls)+"A"+to_string(cows-bulls)+"B";
        return ans;
    }
};

int main()
{


    return 0;
}