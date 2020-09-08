#include <iostream>
#include <vector>
#include <list>
using namespace std;
/*
 * 冒泡排序
 * 比较相邻元素，如果左大，则交换
 * */
void maopao(int* a, int len) {
    if (len == 0)   return;
    for (int i = 0; i < len - 1; i++) {     //代表第i趟排序
        for (int j = 0; j < len - 1- i; j++) {  //代表第j个元素
            if (a[j] > a[j + 1])    swap(a[j],a[j+1]);  //因为是>所以稳定，相等元素前后相对位置不变
        }
    }
}

/*快速排序
 * 1. 找到一个元素的位置，左边都比他小，右边都比他大
 * 2. 左右分别递归
 * */
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



/*插入排序
 * 前面都有序
 * */
void insert(int* a, int len) {
    if (len == 0)   return ;
    for (int i = 1; i < len; i++) {    //代表有序数组的长度
        int num = a[i];     //待插入的元素
        int j = i - 1;
        for (j; j >= 0 && a[j] > num; j--) {  //从第j个开始，往前插入，因为是 > 所以稳定，相等元素前后相对位置不变
            a[j + 1] = a[j];
        }
        a[j + 1] = num;
    }
}

/*希尔排序
 * */
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
}


/*选择排序
 * 找到最小的index，找完后，放到最前面
 * 有可能找到的最小的index，在与当前元素相等的另一个元素之后，这就不稳定了
 * eg. 5 8 5 2 9, 第一次找到2，会把第一个5和2交换，这样两个5的相对位置就变了，就不稳定了
 * */
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

/*堆排序
 * 思路：构建大顶堆，收尾交换后，长度-- 再递归
 * 1. 判断尾索引的奇偶性，单独处理
 * 2. 左右叶子取最大，跟父节点比大小，令父节点为三个节点(1父2子)中最大的
 * 3. 搞定一组之后，索引-2继续向前处理
 * 4. 索引=0时跳出
 * 5. 递归 len - 1
 *
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
    int* p = new int[end - start + 1];
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
}

void list_insert(list<int>& ai, int ele);

/*桶排序
 * */
void bucket(int* a, int len, int bucket_size) {
    int min_value = a[0];
    int max_value = a[0];
    for (int i = 0; i < len; i++) {
        min_value = min_value < a[i] ? min_value : a[i];
        max_value = max_value > a[i] ? max_value : a[i];
    }
    //f = x/10 - min/10
    double each_range = (double)(max_value - min_value) / (double)(bucket_size - 1);
    function<int(int)> f =[min_value,each_range](int x) -> int { return int((double)(x-min_value)/each_range); };
    vector<list<int>> res(bucket_size,list<int>(0));
    for(int i = 0; i < len; i++) {
        list_insert(res[f(a[i])],a[i]);
    }
    int a_idx = 0;
    for(int i = 0; i < bucket_size; i++) {
        for (auto j : res[i]) {
            a[a_idx++] = j;
        }
    }
}

void list_insert(list<int>& ai, int ele) {
    list<int>::iterator it = ai.begin();
    if (ai.size() == 0) {
        ai.push_back(ele);
        return;
    }
    while (it != ai.end()) {
        if (*it == ele) {
            ai.insert(it,ele);
            return;
        }
        if (*it < ele) {
            it++;
        } else {
            ai.insert(it,ele);
            return;
        }
    }
    ai.push_back(ele);
}


int main() {
    int a[8] = {4,5,6,7,3,22,2,1};
    //insert(a,8);
    //shell(a,8);
    //select(a,8);
    //heap(a,8);
    //merge(a,0,7);
    bucket(a,8,3);
    //quick(a,0,7);
    for (int i = 0; i < 8; i++) cout << a[i] << " ";
    return 0;
}
