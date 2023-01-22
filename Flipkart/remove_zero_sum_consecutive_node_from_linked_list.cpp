#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    void clearCache(int sum, ListNode* start, ListNode* end, unordered_map<int, ListNode*>& nodeWithSum) {
        ListNode* p = start;
        while(p!=end) {
            sum+=p->val;
            nodeWithSum[sum]=NULL;
            p=p->next;
        }
    }
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> nodeWithSum;
        ListNode* p = head;
        int sum = 0;
        while(p!=NULL) {
            sum+=p->val;
            if(sum==0) {
                head = p->next;
                nodeWithSum.clear();
            } else if(nodeWithSum[sum]!=NULL) {
                clearCache(sum, nodeWithSum[sum]->next, p, nodeWithSum);
                nodeWithSum[sum]->next = p->next;
            } else nodeWithSum[sum] = p;
            p = p->next;
        }

        return head;
    }
};

int main()
{


    return 0;
}