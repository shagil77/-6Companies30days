#include<bits/stdc++.h>
using namespace std;

class TweetCounts {
    unordered_map<string, vector<int>> tweetTimes;
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweetTimes[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval;
        if(freq == "minute") interval = 60;
        else if(freq == "hour") interval = 3600;
        else if(freq == "day") interval = 86400;

        int n = ceil((double)(endTime-startTime+1)/interval);
        vector<int> ans(n, 0);

        for(auto time:tweetTimes[tweetName]) {
            if(startTime<=time && time<=endTime) {
                int pos = (time-startTime)/interval;
                ans[pos]+=1;
            }
        }

        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

int main() {

    
    return 0;
}