#include<bits/stdc++.h>
using namespace std;

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
    int mountIdx(MountainArray &mountainArr) {
        int l = 0, h = mountainArr.length()-1;
        while(l<=h) {
            int m = l+(h-l)/2;
            int left = mountainArr.get(m-1);
            int right = mountainArr.get(m+1);

            if(left<mountainArr.get(m) && mountainArr.get(m)>right) return m;
            else if(left<mountainArr.get(m) && mountainArr.get(m)<right) l=m;
            else h = m;
        }
        return -1;
    }
    int binarySearch1(int l, int h, int target, MountainArray &mountainArr) {
        while(l<=h) {
            int m = l+(h-l)/2;
            int mid = mountainArr.get(m);

            if(mid==target) return m;
            else if(mid<target) l=m+1;
            else h = m-1;
        }
        return -1;
    }
    int binarySearch2(int l, int h, int target, MountainArray &mountainArr) {
        while(l<=h) {
            int m = l+(h-l)/2;
            int mid = mountainArr.get(m);

            if(mid==target) return m;
            else if(mid<target) h=m-1;
            else l=m+1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int idx = mountIdx(mountainArr);

        int left = binarySearch1(0, idx, target, mountainArr);
        if(left!=-1) return left;

        int right = binarySearch2(idx+1, mountainArr.length()-1, target, mountainArr);
        return right;
    }
};

int main()
{


    return 0;
}