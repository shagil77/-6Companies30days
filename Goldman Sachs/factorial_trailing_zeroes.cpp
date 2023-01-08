#include<bits/stdc++.h>
using namespace std;

class Solution {
    int count5s(int n) {
        int cnt = 0;
        while(n%5==0) {
            cnt++;
            n/=5;
        }
        return cnt;
    }

    int count2s(int n) {
        int cnt = 0;
        while(n%2==0) {
            cnt++;
            n/=2;
        }
        return cnt;
    }
public:
    int trailingZeroes(int n) {
        int cnt2s = 0, cnt5s = 0;
        for(int i=1; i<=n; i++) {
            if(i%2==0) cnt2s+=count2s(i);
            if(i%5==0) cnt5s+=count5s(i);
        }

        return min(cnt2s, cnt5s);
    }
};

int main()
{


    return 0;
}