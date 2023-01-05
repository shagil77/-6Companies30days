#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1) return 1.0;
        return 0.5;

        // Brute Force Method:
        // if(n==1) return 1.0;
        // // first person gets his right seat or he gets wrong seat and 1st person is not sitting on nth seat
        // double ans = (1.0/n) + (n-2)/(n*1.0)*(1-nthPersonGetsNthSeat(n-1));

        // return ans;
    }
};
int main()
{


    return 0;
}