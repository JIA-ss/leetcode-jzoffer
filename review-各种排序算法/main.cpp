#include <iostream>
using namespace std;
/*
 * 冒泡排序
 * 比较相邻元素，如果左大，则交换
 * */
void maopao(int* a, int len) {
    if (len == 0)   return;
    for (int i = 0; i < len - 1; i++) {     //代表第i趟排序
        for (int j = 0; j < len - 1- i; j++) {  //代表第j个元素
            if (a[j] > a[j + 1])    swap(a[j],a[j+1]);
        }
    }
}


/*插入排序
 * 前面都有序
 * */
void insert(int* a, int len) {
    if (len == 0)   return ;
    for (int i = 1; i < len; i++) {    //代表有序数组的长度
        int num = a[i];     //待插入的元素
        int j = i - 1;
        for (j; j >= 0 && a[j] > num; j--) {  //从第j个开始，往前插入，
            a[j + 1] = a[j];
        }
        a[j + 1] = num;
    }
}

/*希尔排序
 * */
void shell(int* a, int len) {
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
        while(i < j && a[j] >= temp)    j--;
        while(i < j && a[i] <= temp)    i++;
        swap(a[i],a[j]);
    }
    swap(a[i],a[start]);
    quick(a,start,i-1);
    quick(a,i+1,end);
}


int main() {
    int a[8] = {4,5,6,7,3,22,2,1};
    //insert(a,8);
    shell(a,8);
    //quick(a,0,7);
    for (int i = 0; i < 8; i++) cout << a[i] << " ";
    return 0;
}
