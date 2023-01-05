#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num:nums) pq.push(num);

        int gcd = numsDivide[0];
        for(int i=1; i<numsDivide.size(); i++) {
            gcd = __gcd(gcd, numsDivide[i]);
            if(gcd<pq.top()) return -1;
        }

        int count = 0, flag = 0;
        while(!pq.empty()) {
            if(gcd==pq.top() || gcd%pq.top()==0) {
                flag=1;
                break;
            }

            count++;
            pq.pop();
        }

        if(flag==1) return count;
        return -1;
    }
};

int main()
{


    return 0;
}