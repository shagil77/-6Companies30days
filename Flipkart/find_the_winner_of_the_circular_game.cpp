#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> person;
    void solve(int i, int k) {
        int n = person.size();
        if(n==1) return;
        
        i=(i+k-1)%n;
        person.erase(person.begin()+i);
        solve(i, k);
    }
public:
    int findTheWinner(int n, int k) {
        for(int i=1;i<=n;i++) person.push_back(i);
        solve(0,k);
        return person[0];
    }
};

int main()
{


    return 0;
}