# 题目描述
>实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
 
## 思路1
>就直接指数乘，逼近n\
然后继续从1开始指数级乘\
当 距离n达到我们设定的阈值的时候，直接for循环，全乘上去就好了，具体看代码
---
## 思路2
>利用递归可以实现log(n)的时间复杂度\
>这个是真牛逼
```c++    
double myPow(double x, long n) {
  bool negative = n < 0 ? true: false;
  if (x == 0) return 0;
  if (n == 0) return 1;
  if (n == 1) return x;
  if (n == -1) return 1/x;
  if (x == 1) return 1;
  if (x == -1) return n % 2 ? -1 : 1;
  double t = myPow(x, n/2);
  if (negative) n= -n;
  if (n % 2) {
      if (negative)   x = 1/x;
      return t * t * x;
  } else {
      return t * t;
  }
}
```