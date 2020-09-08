# 排序算法汇总
[toc]

---
## 冒泡排序
  >每次选取最大的值放到末尾\
  >每循环一次，遍历的长度都减1\
  >两两比较，大的被交换到右侧
- 时间复杂度
    - 平均: O(n2)
    - 最坏: O(n2)
    - 最好: O(n)
- 空间复杂度O(1)
- 稳定

- 代码
```c++
void maopao(int* a, int len) {
    if (len == 0)   return;
    for (int i = 0; i < len - 1; i++) {     //代表第i趟排序
        for (int j = 0; j < len - 1- i; j++) {  //代表第j个元素
            if (a[j] > a[j + 1])    swap(a[j],a[j+1]);  //因为是>所以稳定，相等元素前后相对位置不变
        }
    }
}
```
## 快速排序
> 1. 先把某一个元素放到正确位置(左侧都比它小，右侧都比它大)
> 2. 在该位置的左右分别递归
> 3. 跳出条件为 start >= end
- 时间复杂度
    - 平均: O(nlogn)
    - 最坏: O(n2)
    - 最好: O(nlogn)
- 空间复杂度O(nlogn)
- 不稳定
- 代码
```c++
void quick(int* a, int start, int end) {
    if (start >= end) return;
    int i = start;
    int j = end;
    int temp = a[i];
    while (i < j) {
        while(i < j && a[j] >= temp)    j--;    //因为必须带等号，否则无法跨过自身，就会一直反复横跳，所以注定不稳定
        while(i < j && a[i] <= temp)    i++;
        swap(a[i],a[j]);
    }
    swap(a[i],a[start]);
    quick(a,start,i-1);
    quick(a,i+1,end);
}
```
