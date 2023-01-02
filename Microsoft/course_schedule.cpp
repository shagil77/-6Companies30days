#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        unordered_map<int,int> inDegree;
        queue<int> q;
        int completedCourse = 0;

        for(auto edge:prerequisites) {
            int x = edge[1], y = edge[0];
            if(x==y) return false;
            graph[x].push_back(y);
            inDegree[y]++;
        }

        for(int i=0; i<numCourses; i++) {
            if(inDegree[i]==0) q.push(i);
        }

        if(q.empty()) return false;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCourse++;

            for(auto node:graph[curr]) {
                if(inDegree[node]==1) {
                    q.push(node);
                }
                inDegree[node]--;
            }
        }

        if(completedCourse!=numCourses) return false;

        return true;
    }
};

int main()
{


    return 0;
}