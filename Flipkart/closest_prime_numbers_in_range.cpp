#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int L, int R) {
        long long lim = sqrt(R);
        vector<bool> mark(lim + 1, false);
        vector<long long> primes;
        for (long long i = 2; i <= lim; ++i) {
            if (!mark[i]) {
                primes.emplace_back(i);
                for (long long j = i * i; j <= lim; j += i)
                    mark[j] = true;
            }
        }

        vector<bool> isPrime(R - L + 1, true);
        for (long long i : primes)
            for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
                isPrime[j - L] = false;
        if (L == 1)
            isPrime[0] = false;

        int prev = -1, diff=INT_MAX;
        vector<int> ans = {-1,-1};
        for(int i=0; i<isPrime.size(); i++) {
            if(isPrime[i]) {
                if(prev==-1) prev = i;
                else {
                    if(i-prev<diff) {
                        ans = {prev+L, i+L};
                        diff = i-prev;
                    }
                    prev = i;
                }
            }
        }

        return ans;
    }
};

int main()
{


    return 0;
}