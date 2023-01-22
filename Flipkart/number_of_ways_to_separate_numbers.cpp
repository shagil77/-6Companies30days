#include<bits/stdc++.h>
using namespace std;

class Solution {
    int m = (int)1e9+7;
public:
    int numberOfCombinations(string num) {
        int n = num.length();

        vector<vector<int>> preSum(n+1, vector<int>(n+1,0));
        vector<vector<int>> lcs(n+1, vector<int>(n+1,0));

        for(int i=n-2; i>=0; i--) {
            for(int j=i+1;j<n; j++) {
                if(num[i] == num[j]) lcs[i][j] = 1+lcs[i+1][j+1];
                else lcs[i][j]=0;
            }
        }

        for(int i=0; i<n; i++) {
            for(int l=1; l<=i+1; l++) {
                int j = i-l+1; 
                int temp=0;

                if(num[j]=='0') temp=0;
                else if(j==0) temp= 1;
                else {
                    int maxL2 = 0;

                    if(j<l) maxL2 = j;
                    else {
                        int common_len = lcs[j-l][j];
                        if(common_len>=l || num[j-l+common_len]<num[j+common_len]) maxL2=l;
                        else maxL2 = l-1; 
                    }

                    temp = preSum[j-1][maxL2]%m;
                } 

                preSum[i][l] = (preSum[i][l-1]+temp)%m;
            }
        }

        return preSum[n-1][n]%m;
    }
};

int main() {

    
    return 0;
}