#include<bits/stdc++.h>
using namespace std;

class Solution {
    int distance(vector<int>& p1, vector<int>& p2) {
        int ans = (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
        return ans;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d1 = distance(p1,p2), d2 = distance(p2, p3), d3 = distance(p3, p1);
        if(d1==0 || d2==0 || d3==0) return false;
        
        if(d1==d2 && d1 + d2 == d3) {
            if(distance(p1,p4)==distance(p3,p4) && distance(p1,p4) + distance(p3,p4) == d3) return true;
        } else if(d1==d3 && d1 + d3 == d2) {
            if(distance(p2,p4)==distance(p3,p4) && distance(p2,p4) + distance(p3,p4) == d2) return true;
        } else if(d2==d3 && d2 + d3 == d1) {
            if(distance(p2,p4)==distance(p1,p4) && distance(p2,p4) + distance(p1,p4) == d1) return true;
        }

        return false;
    }
};

int main()
{


    return 0;
}