#include <iostream>
using namespace std;
void printf(int* a, string str) {
    cout << str;
    for(int i = 0; i < 10; i++) {
        cout << a[i] <<" ";
    }
    cout << endl;
}
int i = 1;
void heap_adjust_part(int* a,int root, int len) {
    int lchild = root * 2 + 1;
    int maxChild = lchild;
    if (lchild < len) {
        int rchild = lchild + 1;
        if (rchild < len && a[rchild] > a[lchild])
            maxChild = rchild;
        if (a[maxChild] > a[root]) {    //堆被破坏，需要重新调整
            swap(a[root], a[maxChild]);
            printf(a,"第"+to_string(i++)+"次: ");
            heap_adjust_part(a,maxChild,len);
        }
    }
}

void heap_init(int* a, int root, int len) {
    for(int i = len / 2 - 1; i >= root; i--) {
       heap_adjust_part(a,i,len);
    }
}

void heap_sort(int* a, int len) {
    //初始化堆 -> 遍历每个非叶子节点，进行一次局部的堆调整，可以让所有的最大值上浮，直至根节点 O(n)
    heap_init(a,0,len);
    swap(a[0],a[len-1]);
    for(int i = 1; i < len; i++) {
        //每次把最后的节点交换到根节点后，只需要进行局部调整即可
        //每次局部调整是O(logn),相当于每一层调整一次
        //一共遍历了n次，所以是O(nlogn)
        heap_adjust_part(a,0,len - i);
        swap(a[0],a[len-i-1]);
    }
    //total time   O(n) + O(nlogn) = O(nlogn)
}


int main(){
    int a[10] = {112,112,107,128,121,118,105,113,106,116};
    printf(a,"原始数组: ");
    int len = 10;
    heap_sort(a,len);
    printf(a,"排序后: ");
    //heap_adjust_tree(a,0,len);
    //printf(a,"试一下：");
    return 0;
}