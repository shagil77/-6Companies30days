#include<bits/stdc++.h>
using namespace std;

class Solution {
    // void swap(int* a, int* b) {
    //     int t = *a;
    //     *a = *b;
    //     *b = t;
    // }
    // int partition(vector<int>& nums, int low, int high) {
    //     int pivot = nums[high];

    //     int i=low-1;

    //     for(int j=low; j<high; j++) {
    //         if(nums[j]<pivot) {
    //             i++;
    //             swap(&nums[i], &nums[j]);
    //         }
    //     }

    //     swap(&nums[i+1], &nums[high]);
    //     return i+1;
    // }
    // void quickSort(vector<int>& nums, int low, int high) {
    //     if(low<high) {
    //         int partitionIndex = partition(nums, low, high);

    //         quickSort(nums, low, partitionIndex-1);
    //         quickSort(nums, partitionIndex+1, high);
    //     }
    // }
    void merge(vector<int>& nums, int low, int mid, int high) {
        int m = mid-low+1, n = high-mid;
        vector<int> a(m), b(n);
        for(int i=low;i<=mid;i++) a[i-low] = nums[i];
        for(int i=mid+1;i<=high;i++) b[i-mid-1] = nums[i];

        int i=0, j=0, k=low;
        while(i<m && j<n) {
            if(a[i]<b[j]) {
                nums[k++] = a[i++];
            } else {
                nums[k++] = b[j++];
            }
        }

        while(i<m) {
            nums[k++] = a[i++];
        }

        while(j<n) {
            nums[k++] = b[j++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if(low<high) {
            int m = low+(high-low)/2;
            mergeSort(nums, low, m);
            mergeSort(nums, m+1, high);

            merge(nums, low, m, high);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);

        return nums;
    }
};

int main() {

    
    return 0;
}