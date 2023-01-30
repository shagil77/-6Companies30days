#include<bits/stdc++.h>
using namespace std;

class Solution {
    double R, X, Y;
    double func(double x,  double y) {
        double ans = pow(x-X, 2) + pow(y-Y, 2) - R*R;
        return ans;
    }

    double getSign() {
        
        int n = rand()%10;
        if(n%2==0) return -1.0;
        return 1.0;
    }

    double getRand() {
        double ans = (double)rand()/RAND_MAX;
        return getSign()*ans*R;
    }
public:
    Solution(double radius, double x_center, double y_center) {
        R = radius;
        X = x_center;
        Y = y_center;
    }

    vector<double> randPoint() {
        double x_ans = X + getRand(), y_ans = Y + getRand();
        while(func(x_ans, y_ans)>0) {
            x_ans = X + getRand();
            y_ans = Y + getRand();
        }

        return {x_ans, y_ans};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main() {

    
    return 0;
}