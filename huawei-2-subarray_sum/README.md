# 09.22华为面试题目2
子数组为：某一个数组的一段连续的子数组 \
给定一个数组a, 比如a为`{3,-2,1,-99,5}`, 其存在某个子数组，该子数组的和是所有子数组总最大的，其中这个子数组可以忽略或者不忽略某一个元素

**思路**
> 如果不考虑忽略元素的情况，很简单 \
> 令`dp[i]`为以`a[i]`为结尾的子数组的和 \
>那么 `dp[i] = dp[i - 1] < 0 ? a[i] : dp[i - 1] + a[i]` \
>  \
> 但是题目要求，可以忽略某个值  
>这就需要在此基础上，在定义一个`dpp` \
> 令`dpp[i]`为以`a[i]`结尾的子数组的和 \
> 其中`a[i]`可以选择忽略或者不忽略
> 那么`dpp[i]` 就有两种情况，要么忽略`a[i]`,要么不忽略`a[i]` \
> `dpp[i] = max(dp[i-1],dpp[i-1]+a[i])`
> 1. 忽略 `a[i]` 
>    >  `dp[i] = dp[i-1]`,因为如果忽略了`a[i]`,那么前面一定没有忽略别的 
> 2. 不忽略`a[i]`
>   >   `dp[i] = dpp[i - 1] + a[i]`,因为如果不忽略`a[i]`，那么就有可能忽略前面的，所以需要使用`dpp[i-1]` 
> 

**代码**
```c++
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
```