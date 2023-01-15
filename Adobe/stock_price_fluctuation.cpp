#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
class StockPrice {
    unordered_map<int,int> mp;
    priority_queue<pii> maxHeap; // (price, timestamp)
    priority_queue<pii, vector<pii>, greater<pii>> minHeap; // (price, timestamp)
    int latestTime;
public:
    StockPrice() {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) {
        if(mp[timestamp]==0) {
            mp[timestamp] = price;
            maxHeap.push({price, timestamp});
            minHeap.push({price, timestamp});
        } else {
            mp[timestamp] = price;

            if(maxHeap.top().second == timestamp) maxHeap.pop(); 
            maxHeap.push({price, timestamp});

            if(minHeap.top().second == timestamp) minHeap.pop();
            minHeap.push({price, timestamp});
        }
        latestTime = max(latestTime, timestamp);
    }
    
    int current() {
        return mp[latestTime];
    }
    
    int maximum() {
        int maxPrice = 0;
        while(mp[maxHeap.top().second]!=maxHeap.top().first) maxHeap.pop();
        maxPrice = maxHeap.top().first;
        return maxPrice;
    }
    
    int minimum() {
        int minPrice = 0;
        while(mp[minHeap.top().second]!=minHeap.top().first) minHeap.pop();
        minPrice = minHeap.top().first;
        return minPrice;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

int main()
{


    return 0;
}