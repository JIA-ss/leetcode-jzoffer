#include <iostream>
#include <vector>

using namespace std;
int sub_sum(vector<int>& a) {
    //dp[i]，代表以a[i]结尾的，连续子数组的和的最大值
    vector<int> dp(a.size(),a[0]);
    for(int i = 1; i < a.size(); i++) {
        dp[i] = dp[i - 1] < 0 ? a[i] : dp[i - 1] + a[i];
    }
    //那么，可以忽略某个值的结果，即为忽略和不忽略的最大值
    vector<int> dpp(a.size(),a[0]);
    for(int i = 1; i < a.size(); i++) {
        //不忽略a[i]的情况 dpp[i-1]+a[i]
        //忽略a[i]的情况 dp[i-1]
        dpp[i] = max(dp[i - 1],dpp[i-1] + a[i]);
    }
    int res = dpp[0];
    for(int i = 0; i < a.size(); i++) {
        res = res > dpp[i] ? res : dpp[i];
    }
    return res;
}
int f(vector<int>& a) {
    vector<int> dp(a.size(),a[0]);
    for(int i = 1; i < a.size(); i++) {
        dp[i] = dp[i-1] < 0 ? a[i] : dp[i-1] + a[i];
    }

    vector<int> dpp(a.size(), a[0]);
    int sum = dpp[0];
    for(int i = 1; i < a.size(); i++) {
        dpp[i] = max(dp[i-1], dpp[i - 1] + a[i]);
        sum = sum > dpp[i] ? sum : dpp[i];
    }
    return sum;

}
int main() {
    vector<int> a = {3,-2,1,-99,5};
    cout << f(a);
    return 0;
}
