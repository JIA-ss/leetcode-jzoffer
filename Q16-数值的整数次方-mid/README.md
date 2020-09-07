# 题目描述
>实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
 
## 思路
就直接指数乘，逼近n\
然后继续从1开始指数级乘\
当 距离n达到我们设定的阈值的时候，直接for循环，全乘上去就好了，具体看代码