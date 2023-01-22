#include<bits/stdc++.h>
using namespace std;

#define pis pair<int,string>
bool compare(const pis& s1, const pis& s2) {
    if(s1.first == s2.first) 
        return lexicographical_compare(s1.second.begin(), s1.second.end(), s2.second.begin(), s2.second.end());
    
    return s1.first>s2.first;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<pis> freq;

        for(auto word:words) {
            mp[word]++;
        }

        for(auto [s,c]:mp) {
            freq.push_back({c,s});
        }

        sort(freq.begin(), freq.end(), compare);
        vector<string> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(freq[i].second);
        }

        return ans;
    }
};

int main()
{


    return 0;
}