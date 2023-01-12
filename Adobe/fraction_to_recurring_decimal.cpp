#include<bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    string fractionToDecimal(int num, int den) {
        if(num==0) return "0";
        long n = num, d = den;
        string res = "";

        if(n < 0 ^ d < 0) res+="-";
        
        n = abs(n), d=abs(d);

        res+=to_string(n/d);
        if(n%d==0) return res;

        res+=".";

        unordered_map<int,int> mp;

        for(long r=n%d; r!=0; r%=d) {
            // remainder has been observed again, hence we reached the end of our recurring part
            if(mp.count(r)>0) {
                res.insert(mp[r], 1, '(');
                res+=")";
                break;
            }

            mp[r]=res.size();
            r*=10;
            res+=to_string(r/d);
        }

        return res;
    }
};

int main()
{


    return 0;
}