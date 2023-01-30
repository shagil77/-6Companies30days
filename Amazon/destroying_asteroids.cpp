#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        ll ans = mass;
        for(auto asteroid:asteroids) {
            if(ans>=asteroid) ans+=asteroid;
            else return false;
        }

        return true;
    }
};

int main() {

    
    return 0;
}