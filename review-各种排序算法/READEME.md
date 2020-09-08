# 排序算法汇总

[toc]

---

## 交换类排序

### 冒泡排序

  >每次选取最大的值放到末尾\
  >每循环一次，遍历的长度都减1\
  >两两比较，大的被交换到右侧
- 时间复杂度
    - 平均: O(n2)
    - 最坏: O(n2)
    - 最好: O(n)，可以改进代码，判断一次都没交换的话，直接返回，所以可以改进为O(n)
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
### 快速排序

> 1. 先把某一个元素放到正确位置(左侧都比它小，右侧都比它大)
> 2. 在该位置的左右分别递归
> 3. 跳出条件为 start >= end
- 时间复杂度
    - 平均: O(nlogn)
    - 最坏: O(n2) (降序排列时，几乎退化成冒泡)
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
      	//这里先走j 再走i，是为了避免，把最后一个大的元素放到队首
        while(i < j && a[j] >= temp)    j--;    //因为必须带等号，否则无法跨过自身，就会一直反复横跳，所以注定不稳定
        while(i < j && a[i] <= temp)    i++;
        swap(a[i],a[j]);
    }
    swap(a[i],a[start]);
    quick(a,start,i-1);
    quick(a,i+1,end);
}
```

---

## 插入类排序

### 插入排序

> 默认前面有序
>
> 找到前面属于该元素的位置
>
> 插入

- 时间复杂度
  - 平均: O(n2)
  - 最坏: O(n2) 
  - 最好: O(n)
- 空间复杂度: O(1)
- 稳定
- 代码

```c++
void insert(int* a, int len) {
    if (len == 0)   return ;
    for (int i = 1; i < len; i++) {    //代表有序数组的长度
        int num = a[i];     //待插入的元素
        int j = i - 1;
      //从第j个开始，往前插入，因为是 > 所以稳定，相等元素前后相对位置不变
        for (j; j >= 0 && a[j] > num; j--) {  
            a[j + 1] = a[j];
        }
        a[j + 1] = num;
    }
}
```

### 希尔排序

> 分组，每组都用插入排序，直至分组的increase == 1

- 时间复杂度
  - 平均: O(nlogn)
  - 最坏: O(n2)
  - 最好: O(n)
- 空间复杂度：O(1)
- 不稳定(因为可能被分配到不同的组，所以必然不稳定)
- 代码

```c++
void shell(int* a, int len) {   //因为相同元素可能被包含在不同分组里面，所以不稳定
    int inc = len;
    while (inc > 1) {
        inc /= 2;
        for (int i = inc; i < len; i += inc) {
            int num = a[i];
            int j = i - inc;
            for(j; j >= 0 && a[j] > num; j -= inc) {
                a[j + inc] = a[j];
            }
            a[j + inc] = num;
        }
    }

```

---

## 选择类排序

### 选择排序

> 选择一个最小的元素，与队首交换

- 时间复杂度：

  - 平均: O(n2)
  - 最坏: O(n2)
  - 最好: O(n2)

- 空间复杂度：O(1)

- 不稳定

  > 最小的元素，可能在相同元素的后面 
  >
  > eg
  >
  > 5 8 5 2 3，
  >
  > 此时选中元素为5，
  >
  > 后面最小元素为2，
  >
  > 那么就会变为 2 8 5 5 3，两个5的相对位置变了
  >
  > 所以不稳定

- 代码

```c++
void select(int* a, int len) {
    if (len == 0)   return;
    for (int i = 0; i < len; i++) {
        int idx = i;
        for(int j = i + 1; j < len; j++) {
            if (a[j] < a[idx])    idx = j;
        }
        swap(a[i],a[idx]);
    }
}
```

### 堆排序

> 构建大根堆，队首队尾交换，len--，递归
>
> 核心思想：每个节点和他的兄弟节点、父节点进行一个比较，令最大的为父节点即可

- 时间复杂度

  - 平均：O(nlogn)
  - 最好：O(nlogn)
  - 最坏：O(nlogn)

- 空间复杂度：O(1)

- 不稳定

  > eg: 3 27 6 27
  >
  > ​		3
  >
  > ​	27(1)	6
  >
  > 27(2)
  >
  > ​		↓
  >
  > ​		27(1)
  >
  > ​	3	6
  >
  > 27(2)
  >
  > ​		↓
  >
  > ​		27(2)
  >
  > ​	3	6
  >
  > 27(1)
  >
  > 再往后，27(1)就永远在27(2)后面了，所以不稳定

- 代码

```c++

/*堆排序
 * 思路：构建大顶堆，收尾交换后，长度-- 再递归
 * 1. 判断尾索引的奇偶性，单独处理
 * 2. 左右叶子取最大，跟父节点比大小，令父节点为三个节点(1父2子)中最大的
 * 3. 搞定一组之后，索引-2继续向前处理
 * 4. 索引=0时跳出
 * 5. 递归 len - 1
 * */
void heap(int* a, int len) {
    if (len <= 1)   return;
    int end = len - 1;
    if (end % 2 ) {
       if (a[(end - 1) / 2] < a[end])   { swap(a[end],a[(end-1)/2]); }
       end--;
    }
    //一定是右子叶
    while (end > 0) {
        if (a[end] >= a[end - 1] && a[end] > a[end/2 - 1])   swap(a[end],a[end/2 -1]);
        else if (a[end] < a[end - 1] && a[end - 1] > a[end/2 - 1]) swap(a[end - 1], a[end/2 - 1]);
        end -= 2;
    }
    swap(a[0],a[len - 1]);
    heap(a, len - 1);
}
```

---

## 归并排序

- 时间复杂度：
  - 平均：O(nlogn)
  - 最好：O(nlogn)
  - 最坏：O(nlogn)
- 空间复杂度：O(n)
- 稳定
- 代码

```c++
/*归并排序
 * 1. 拆分成 左右两个 有序数组
 * 2. 将两个有序数组  合并成1个有序数组
 * */
void merge(int* a, int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    merge(a,start,mid);
    merge(a,mid + 1, end);
    if (a[mid] <= a[mid + 1]) return;
    int* p = new int[end - start + 1];	//这里可以优化，让所有的递归都共用一个dp，即可实现O(n)空间复杂度
    int l_idx = start;
    int r_idx = mid + 1;
    int p_idx = 0;
    while (l_idx <= mid && r_idx <= end) {
        if (a[l_idx] <= a[r_idx]) {
            p[p_idx++] = a[l_idx++];
        } else {
            p[p_idx++] = a[r_idx++];
        }
    }
    while (l_idx <= mid) {
        p[p_idx++] = a[l_idx++];
    }
    while (r_idx <= end) {
        p[p_idx++] = a[r_idx++];
    }
    p_idx = 0;
    for(int i = start; i <= end; i++) {
        a[i] = p[p_idx++];
    }
    delete[] p;

```

