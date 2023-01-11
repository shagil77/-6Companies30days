#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Transaction {
        string name;
        int time;
        int amount;
        string city;
        bool marked;
        Transaction(string n, int t, int a, string c) {
            name=n;
            time=t;
            amount=a;
            city=c;
            marked=false;
        }
    };
    Transaction parse(string transaction) {
        vector<int> comma;
        for(int i=0; i<transaction.length(); i++) {
            if(transaction[i]==',') comma.push_back(i);
        }
        Transaction t = Transaction(
            transaction.substr(0, comma[0]),
            stoi(transaction.substr(comma[0]+1, comma[1]-comma[0]+1)),
            stoi(transaction.substr(comma[1]+1, comma[2]-comma[1]+1)),
            transaction.substr(comma[2]+1)
        );
        return t;
    }
    static bool compareByTime(const Transaction& a, const Transaction& b) {
        return a.time < b.time;
    }
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<Transaction>> mp;
        // vector<Transaction> trans;
        int n = transactions.size();

        for(auto transaction:transactions) {
            Transaction t = parse(transaction);
            // trans.push_back(t);
            mp[t.name].push_back(t);
        }

        vector<string> result;

        for(auto &[name,trans]:mp) {
            sort(trans.begin(), trans.end(), compareByTime);

            for(int i=0; i<trans.size(); i++) {
                if(trans[i].amount>1000) {
                    trans[i].marked = true;
                    result.push_back(trans[i].name+","+to_string(trans[i].time)+","+to_string(trans[i].amount)+","+trans[i].city);
                }

                if(i>0 && trans[i].time<=trans[i-1].time+60) {
                    int r = i-1;
                    while(r>=0 && trans[i].time<=trans[r].time+60) {
                        if(trans[r].city!=trans[i].city) {
                            if(!trans[r].marked) {
                                result.push_back(trans[r].name+","+to_string(trans[r].time)+","+to_string(trans[r].amount)+","+trans[r].city);
                                trans[r].marked = true;
                            }
                            if(!trans[i].marked) {
                                result.push_back(trans[i].name+","+to_string(trans[i].time)+","+to_string(trans[i].amount)+","+trans[i].city);
                                trans[i].marked = true;
                            }
                        }
                        r--;
                    }
                }
            }
        }

        return result;
    }
};

int main()
{


    return 0;
}