#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int i=0, j=0;
        int a=0, b=0, c=0;
        long long int count=0;
        int startCount=0;

        if(s[j]=='a') a++;
        else if(s[j]=='b') b++;
        else if(s[j]=='c') c++;

        while(j<n && i<n) {

            if(a>0 && b>0 && c>0) {
                // prev_count + next_count
                if(j==n) count+=(n-j+1)*(i-startCount+1);
                else count+=(n-j)*(i-startCount+1);
                startCount=i+1;

                if(s[i]=='a') a--;
                else if(s[i]=='b') b--;
                else if(s[i]=='c') c--;

                i++;
            } 

            if(!(a>0 && b>0 && c>0)) {
                j++;

                if(s[j]=='a') a++;
                else if(s[j]=='b') b++;
                else if(s[j]=='c') c++;
            }
        }

        return count;
    }
};

int main()
{


    return 0;
}