#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n, 0);
        
        int j=0;
        for(int i=1; i<n; i++) {
            while(j>0 && s[i]!=s[j]) j = lps[j-1];

            if(s[i]==s[j]) {
                j++;
                lps[i] = j;
            }
        }

        return s.substr(0,lps[n-1]);
    }
};

int main()
{


    return 0;
}