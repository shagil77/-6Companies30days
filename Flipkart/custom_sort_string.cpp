#include<bits/stdc++.h>
using namespace std;

#define pic pair<int,char>
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        priority_queue<pic, vector<pic>, greater<pic>> pq;

        for(int i=0; i<order.length(); i++) mp[order[i]] = i+1;
        for(int i=0; i<s.length(); i++) pq.push({mp[s[i]], s[i]});

        string ans = "";
        while(!pq.empty()) {
            ans += pq.top().second;
            pq.pop();
        }

        return ans;
    }
};

int main() {

    
    return 0;
}