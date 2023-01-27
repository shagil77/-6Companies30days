#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int n = fruits.size(), c=0;
        int i=0, j=0;
        int ans = 0;
        while(j<n) {
            if(count[fruits[j]]==0) c++;
            count[fruits[j]]++;

            if(c<=2) {
                ans = max(ans, j-i+1);
            } else {
                while(i<=j) {
                    count[fruits[i]]--;
                    if(count[fruits[i]]==0) {
                        c--;
                        i++;
                        break;
                    }
                    i++;
                }
            }
            j++;
        }

        return ans;
    }
};

int main() {

    
    return 0;
}