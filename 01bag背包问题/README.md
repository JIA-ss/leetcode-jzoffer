# 背包问题
**问题描述**
> 有M个物品，每个物品重量为Wi，每个物品价值为Vi \
> 你有一个背包，所能容纳的重量为N \
> 问：你的背包能够带走的最大价值为多少？
---
**解题方法** 
> 采用动态规划的方式解决 \
> `dp[i][j]` 代表:背包容量为j时, 前i个物品所能达到的最大价值 \
> 递推公式为: \
> `dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + v[i])` \
> \
> **解释**
> > `dp[i-1][j]`代表第i个物品不放入背包时的最优解 \
> > \
> > `dp[i-1][j-w[i]]` 代表预留了第i个物品的大小时的最优解 \
> > （或者说是，当背包刚好能装下第i个物品时的最优解) \
> > \
> > `dp[i-1][j-w[i]] + v[i]` 代表装入第i个物品后的最优解 \
> > \
> > 所以`dp[i][j]`需要取二者之中较大的一个(装i的最优解 还是不装i的最优解)
---
**代码**
```c++
int bag_0_1_question(int products_count,int capacity,vector<int> &weights,vector<int> &values) {
    vector<vector<int> > res(products_count + 1, vector<int>(capacity + 1, 0));
    for(int i = 1; i <= products_count; i++) {
        for(int j = 1; j <= capacity; j++) {
            if(weights[i - 1] > j) { //当容量不足，必然无法放第i个物品, 注意第i个物品的重量是weights[i-1]，同理values[i-1] 这是一个大坑
                res[i][j] = res[i-1][j];
            } else {
                res[i][j] = max(res[i-1][j],res[i-1][j-weights[i - 1]] + values[i - 1]);
            }
        }
    }
    return res[products_count][capacity];
}
```
---
**空间优化**
> 可以简化为一维数组 \
> `f[i]`代表背包容量为i的最优值 \
> `f[i] = max(f[i],f[i-weight[i]] + value[i]`