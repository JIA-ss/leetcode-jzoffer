#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        //dp[i][0] = false (i >= 1)
        for(int i = 1; i <= p.size(); i++) {
            if (p[i - 1] == '*')    dp[0][i]=dp[0][i-2];//第一个肯定不会是*，所以这里不加越界判断了
        }

        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j - 2] ||                      //用0次
                               ((p[j-2] == s[i-1] || p[j-2] =='.')&&dp[i-1][j]); //用多次
                }
            }
        }

        return dp[s.size()][p.size()];
    }
};

int main() {
    Solution s;
    string s1 = "aa";
    string s2 = "a*";
    cout << s.isMatch(s1,s2);
    return 0;
}
