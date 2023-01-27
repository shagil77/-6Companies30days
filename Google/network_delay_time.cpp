#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n+1, INT_MAX); 
        vector<vector<pii>> adj(n+1);

        int src = k;
        for(auto time:times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v,w});
        }

        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()) {
            auto [d,node] = pq.top();
            pq.pop();

            for(auto [child, curr_dist]:adj[node]) {
                if(d+curr_dist<dist[child]) {
                    dist[child] = d+curr_dist;
                    pq.push({dist[child], child});
                }
            }
        }

        int mx = INT_MIN;
        for(int i=1; i<=n; i++) {
            if(dist[i]==INT_MAX) return -1;
            mx = max(mx, dist[i]);
            // cout<<dist[i]<<" ";
        }
        return mx;
        
    }
};

int main() {

    
    return 0;
}