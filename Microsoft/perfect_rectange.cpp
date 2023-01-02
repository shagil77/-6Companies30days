#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, int> pointCount;
    unordered_map<int, int> cornerTypeCount;
    unordered_map<string, int> tLeft, tRight, bLeft, bRight;

    int minX, maxX, minY, maxY;

    bool checkCorners(pair<int, int> point) {
        string p = to_string(point.first)+" "+to_string(point.second);
        if(pointCount[p]!=1) return false;
        return true;
    }

    void calculateCorners(pair<int,int> p) {
        minX = min(minX, p.first);
        maxX = max(maxX, p.first);
        minY = min(minY, p.second);
        maxY = max(maxY, p.second);
    }

    bool recordCount(pair<int, int> point) {
        calculateCorners(point);
        string p = to_string(point.first)+" "+to_string(point.second);
        if(pointCount[p]==0) {
            pointCount[p]++;
            cornerTypeCount[1]++;
        } else if(pointCount[p]==1) {
            pointCount[p]++;
            cornerTypeCount[1]--;
            cornerTypeCount[2]++;
        } else if(pointCount[p]==2) {
            pointCount[p]++;
            cornerTypeCount[2]--;
            cornerTypeCount[3]++;
        } else if(pointCount[p]==3) {
            pointCount[p]++;
            cornerTypeCount[3]--;
            cornerTypeCount[4]++;
        } else if(pointCount[p]==4) {
            return false;
        } 
        return true;
    }
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int> coords = rectangles[0];
        minX = min(coords[0], coords[2]);
        maxX = max(coords[0], coords[2]);
        minY = min(coords[1], coords[3]);
        maxY = max(coords[1], coords[3]);
        long long int area = 0;

        for(auto coordinates:rectangles) {
            pair<int, int> tL, tR, bL, bR;
            bL = {coordinates[0], coordinates[1]};
            tR = {coordinates[2], coordinates[3]};
            bR = {coordinates[2], coordinates[1]};
            tL = {coordinates[0], coordinates[3]};
            long long int a = coordinates[2]-coordinates[0];
            long long int b = coordinates[3]-coordinates[1];
            area += a*b;

            string s1 = to_string(coordinates[0])+" "+to_string(coordinates[1]);
            string s2 = to_string(coordinates[2])+" "+to_string(coordinates[3]);
            string s3 = to_string(coordinates[2])+" "+to_string(coordinates[1]);
            string s4 = to_string(coordinates[0])+" "+to_string(coordinates[3]);

            if(bLeft[s1]!=0) return false;
            if(bRight[s2]!=0) return false;
            if(tLeft[s3]!=0) return false;
            if(tRight[s4]!=0) return false;

            bLeft[s1]++;
            bRight[s2]++;
            tLeft[s3]++;
            tRight[s4]++;

            if(!recordCount(bL)) return false;
            if(!recordCount(bR)) return false;
            if(!recordCount(tL)) return false;
            if(!recordCount(tR)) return false;
        }

        if(cornerTypeCount[1]!=4) return false;
        if(cornerTypeCount[3]!=0) return false;

        if(!checkCorners({minX, minY})) return false;
        if(!checkCorners({minX, maxY})) return false;
        if(!checkCorners({maxX, minY})) return false;
        if(!checkCorners({maxX, maxY})) return false;

        long long int a = maxX-minX;
        long long int b = maxY-minY;
        long long int check_area = a*b;
        if(area != check_area) return false;

        return true;
    }
};



int main()
{


    return 0;
}