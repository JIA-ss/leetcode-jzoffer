# unordered_map使用方法
> 留意一下，结构体或类中的函数，如果函数不需要改变成员变量，函数体前一定要加**`const`**

-  自定义结构体 + 重载operator==
  ```c++
struct P {
    int a;
    int b;
    bool operator==(const P& p) const { //这里的const一定记得加
        return this->a == p.a;
    }
};
   ```
- 定义hashmap(需要写成仿函数的形式)
```c++
struct P_Hash {
    std::size_t operator()(const P& p) const {
        return p.a % 10;
    }
};
```
- 使用unordered_map
```c++
unordered_map<P,int,P_Hash> mp;
```