#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

class Solution {
    vector<vector<int>> tree;
    vector<int> dis, par;
    void dfs(int node, int parent, int dist) {
        dis[node]=dist;
        par[node]=parent;
        for(auto child:tree[node]) {
            if(child==parent) continue;
            dfs(child, node, dist+1);
        }
    }

    int dfs2(int node, int parent, vector<int>& amount) {
        int sum = amount[node];
        int s = INT_MIN;
        for(auto child:tree[node]) {
            if(child!=parent) s = max(s, dfs2(child, node, amount));
        }

        if(s==INT_MIN) return sum;
        return sum+s;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        tree.resize(n, vector<int>());
        dis.resize(n);
        par.resize(n);
        for(auto edge:edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        dfs(0,0,0);
        int curr = bob;
        int bob_dist = 0;
        while(curr!=0) {
            if(bob_dist<dis[curr]) amount[curr]=0;
            else if(bob_dist==dis[curr]) amount[curr]/=2;
            curr=par[curr];
            bob_dist++;
        }

        return dfs2(0,0,amount);
    }
};

int main()
{


    return 0;
}