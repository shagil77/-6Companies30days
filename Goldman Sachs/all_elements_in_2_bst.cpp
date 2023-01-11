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
    vector<int> inorder1, inorder2;
    // void solve(TreeNode* root1, TreeNode* root2) {
    //     if(root1 == NULL && root2 == NULL) return;
    //     else if(root1!=NULL) {
    //         solve(root1->left, root2);
    //         ans.push_back(root1->val);
    //         solve(root1->right, root2);
    //     }
    //     else if(root2!=NULL) {
    //         solve(root1, root2->left);
    //         ans.push_back(root2->val);
    //         solve(root1, root2->right);
    //     } else {
    //         solve(root1->left, root2->left);
    //         // if(root1->val<root2->val) {
    //         //     ans.push_back(root1->val);
    //         // } else {
    //         //     ans.push_back(root2->val);
    //         // }
    //         solve(root1->right, root2->right);
    //     }
    // }
    void solve1(TreeNode* root) {
        if(root==NULL) return;

        solve1(root->left);
        inorder1.push_back(root->val);
        solve1(root->right);
    }
    void solve2(TreeNode* root) {
        if(root==NULL) return;

        solve2(root->left);
        inorder2.push_back(root->val);
        solve2(root->right);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        solve1(root1);
        solve2(root2);

        int m=inorder1.size(), n=inorder2.size();
        vector<int> ans(m+n);

        int i=0, j=0, k=0;
        while(i<m && j<n) {
            if(inorder1[i]<inorder2[j]) {
                ans[k++]=inorder1[i++];
            } else {
                ans[k++]=inorder2[j++];
            }
        }

        while(i<m) {
            ans[k++]=inorder1[i++];
        }

        while(j<n) {
            ans[k++]=inorder2[j++];
        }

        return ans;
    }
};

int main()
{


    return 0;
}