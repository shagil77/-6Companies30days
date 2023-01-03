#include<bits/stdc++.h>
using namespace std;

class Solution {
    int d;
    long long int count;
    void merge(vector<int>& arr, int low, int mid, int high) {
        int i=low, j=mid+1;
        while(i<=mid && j<=high) {
            if(arr[i]<=(arr[j]+d)) {
                count+=(high-j+1);
                i++;
            } else {
                j++;
            }
        }

        sort(arr.begin()+low, arr.begin()+high+1);
        return;
    }
    void countInequality(vector<int>& arr, int low, int high) {
        if(low<high) {
            int mid =(low+high)/2;

            countInequality(arr, low, mid);
            countInequality(arr, mid+1, high);

            merge(arr, low, mid, high);
        }
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> arr(n);
        d = diff;
        count = 0;

        for(int i=0; i<n; i++) {
            arr[i] = nums1[i]-nums2[i];
        }

        countInequality(arr, 0, n-1);
        return count;
    }
};

int main()
{


    return 0;
}