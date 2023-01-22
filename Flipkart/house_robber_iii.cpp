#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 #define pii pair<int,int>
class Solution {
    // Solution 1 (4 functions calls in each recursive call) [TLE]
    // int maxSum(TreeNode* root, bool isIncluded = false) {
    //     if(root==NULL) return 0;

    //     int temp = maxSum(root->left, false)+maxSum(root->right, false);
    //     if(isIncluded) return temp;

    //     return max(root->val+maxSum(root->left, true)+maxSum(root->right, true), temp);
    // }



    // Solution 2 (2 recursive calls in each recursive call) [AC]
    pii maxSum(TreeNode* root) {
        if(root==NULL) return {0,0};

        pii leftSum = maxSum(root->left);
        pii rightSum = maxSum(root->right);

        // when root val is included then the immediate child cannot be included: 
        int withRoot = root->val+leftSum.second+rightSum.second; 

        // when root val is not included then the immediate child can or cannot be included
        int withoutRoot= max(leftSum.first, leftSum.second)+max(rightSum.first, rightSum.second);

        return {withRoot, withoutRoot};
    }
public:
    int rob(TreeNode* root) {
        pii ans = maxSum(root);
        return max(ans.first, ans.second);
    }
};

int main() {

    
    return 0;
}