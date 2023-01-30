#include<bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {
    int m = (int)1e9+7;
public:
    int maxSumMinProduct(vector<int>& n) {
        long res = 0;
        vector<long> dp(n.size() + 1), st;
        for (int i = 0; i < n.size(); ++i)
        dp[i + 1] = dp[i] + n[i];
        for (int i = 0; i <= n.size(); ++i) {
            while (!st.empty() && (i == n.size() || n[st.back()] > n[i])) {
                int j = st.back();
                st.pop_back();
                res = max(res, n[j] * (dp[i] - dp[st.empty() ? 0 : st.back() + 1]));
            }
            st.push_back(i);
        }
        return res % 1000000007;
    }
};

int main() {

    
    return 0;
}