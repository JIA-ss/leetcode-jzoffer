#include <iostream>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    set<pair<int,int>> judge;
    int result = 0;
    //计算i j 的数位和
    int cal_byte_sum(int i, int j) {
        int res = 0;
        while (i > 9) {
            res += i % 10;
            i /= 10;
        }
        res += i;
        while (j > 9) {
            res += j % 10;
            j /= 10;
        }
        res += j;
        return res;
    }
    int movingCount(int m, int n, int k) {
        //dfs(0,0,k,m,n);
        if (k == 0) return 1;
        bfs(0,0,k,m,n);
        return result;
    }
    void dfs(int m, int n, int k, int m_limit, int n_limit) {
        if (judge.find(make_pair(m,n)) != judge.end()
            || cal_byte_sum(m,n) > k
            || m >= m_limit
            || n >= n_limit)
        {
            return;
        }
        result++;
        judge.insert(make_pair(m,n));
        dfs(m+1, n, k, m_limit, n_limit);
        dfs(m, n+1, k , m_limit, n_limit);
    }
    void bfs(int m, int n, int k, int m_limit, int n_limit) {
        queue<pair<int,int>> q;
        if (k == 0) { result = 1; }
        judge.insert(make_pair(0,0));
        q.push(make_pair(0,0));
        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            if (cal_byte_sum(ele.first,ele.second) <= k) {
                result++;
                if (ele.first + 1 < m_limit
                    && judge.count(make_pair(ele.first +1 ,ele.second)) == 0)
                {
                    auto it= make_pair(ele.first + 1, ele.second);
                    judge.insert(it);
                    q.push(it);
                }
                if (ele.second + 1 < n_limit
                    && judge.count(make_pair(ele.first,ele.second + 1)) == 0)
                {
                    auto it = make_pair(ele.first, ele.second + 1);
                    judge.insert(it);
                    q.push(it);
                }
            }
        }
    }
};


int main() {
    Solution s;
    cout << s.movingCount(3,2,17);
    return 0;
}
