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

class Solution {
    int ans=0;
    pair<int,int> solve(TreeNode* root) {
        if(root==NULL) return {0,0};

        auto [s1,c1]=solve(root->left);
        auto [s2,c2]=solve(root->right);

        int s = s1+s2+root->val, c = c1+c2+1;
        int avg = round(s/c);
        if(avg==root->val) ans++;

        return {s, c};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};

int main()
{


    return 0;
}