#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        vector<int> f(32);
        f[0]=1;
        f[1]=2;

        for(int i=2; i<32; i++) 
            f[i] = f[i-1]+f[i-2];

        int i=30; // MSB
        int sum=0, prev_bit = 0;
        while(i>=0) {
            if((n&(1<<i))!=0) {
                sum+=f[i];
                
                if(prev_bit==1) { 
                    // This accounts for the presence of 2 consecutive bits and hence no 
                    // further number can be generated which is <= n
                    sum--;
                    break;
                }

                prev_bit = 1;
            } else prev_bit=0;
            i--;
        }

        return sum+1;
    }
};

int main()
{

    unordered_map<string, double> mp;
    cout<<mp["shagil"];
    return 0;
}