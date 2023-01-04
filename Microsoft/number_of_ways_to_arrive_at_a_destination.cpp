#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pll pair<ll,ll>
class Solution {
    int mod = 1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph;
        graph.resize(n, vector<pll>());
        priority_queue<pll, vector<pll>, greater<pll>> pq; // {dist, node}
        vector<ll> ways(n, 0);
        vector<ll> dis(n, LONG_MAX);

        for(auto road:roads) {
            ll u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        ways[0]=1;
        dis[0]=0;
        pq.push({0,0});

        while(!pq.empty()) {
            ll prev_dist = pq.top().first;
            ll u = pq.top().second;
            pq.pop();
            if(prev_dist>dis[u]) continue;

            for(auto it:graph[u]) {
                ll v = it.first;
                ll dist = it.second;

                ll nextDist = prev_dist+dist;
                if(nextDist < dis[v]) {
                    dis[v] = nextDist;
                    ways[v] = ways[u];
                    pq.push({dis[v], v});
                } else if(nextDist == dis[v]) {
                    ways[v] = (ways[v]+ways[u])%mod;
                }
            }
        }

        return ways[n-1];
    }
};

int main()
{


    return 0;
}