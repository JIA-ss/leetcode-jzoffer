#include <iostream>
using namespace std;
struct CalRes {
    double value;
    long long pow_value;
    CalRes(double x, long long n):value(x),pow_value(n){}
};

class Solution {
public:
    CalRes pow_tool(double x, int n) {
        long long temp = 2;
        while (temp < n) {
            x *= x;
            temp *= 2;
        }
        CalRes res(x,temp/2);
        return res;
    }
    double myPow(double x, int N) {
        bool negative = false;
        long n = (long)N;
        if (x == 0) return 0;
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        if (x == 1) return 1;
        if (x == -1) return n % 2 == 1 ? -1 : 1;
        if (N < 0)  {
            negative = true;
            n = -n;
        }
        CalRes tmp = pow_tool(x,n);
        double res = tmp.value;
        int remain = n - tmp.pow_value;
        while (remain > 8) {
            tmp = pow_tool(x, remain);
            res *= tmp.value;
            remain -= tmp.pow_value;
        }
        for (int i = 0; i < remain; i++) {
            res *= x;
        }
        if (negative) res = 1/res;
        return res;
    }
};
int main() {
    Solution s;
    cout << s.myPow(3,5);
    return 0;
}
