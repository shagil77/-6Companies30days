#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pii, vector<pii>> profitQ;
        priority_queue<pii, vector<pii>, greater<pii>> capitalQ;

        int n = profits.size();

        for(int i=0; i<n; i++) {
            capitalQ.push({capital[i],profits[i]});
        }
        
        for(int i=0; i<k; i++) {
            while(!capitalQ.empty() && capitalQ.top().first<=w) {
                auto [c,p] = capitalQ.top();
                capitalQ.pop();
                profitQ.push({p,c});
            }

            if(profitQ.empty()) break;
            auto [p,c] = profitQ.top();
            profitQ.pop();
            w+=p;
        }
        

        return w;
    }
};

int main()
{
    Solution s;
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,1};
    cout<<s.findMaximizedCapital(2, 0, profits, capital);

    return 0;
}