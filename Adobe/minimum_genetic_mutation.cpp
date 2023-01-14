#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool hasEdge(string a, string b) {
        int count=0;
        for(int i=0; i<8; i++) {
            if(a[i]!=b[i]) {
                count++;
            }
        }

        return count==1;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(bank.size()==0) return -1;
        if(find(bank.begin(), bank.end(), endGene)==bank.end()) return -1;
        if(startGene==endGene) return 0;
        if(hasEdge(startGene, endGene)) return 1;

        int n = bank.size();
        unordered_map<string, bool> vis;
        queue<string> q;

        q.push(startGene);
        vis[startGene]=true;

        int level=0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                string curr = q.front();
                q.pop();

                for(auto gene:bank) {
                    if(!vis[gene] && hasEdge(curr, gene)) {
                        if(gene==endGene) return level+1;
                        q.push(gene);
                        vis[gene] = true;
                    }
                }
            }
            level++;
        }

        return -1;
    }
};

int main()
{


    return 0;
}