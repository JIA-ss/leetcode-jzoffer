#include <iostream>
#include <queue>
using namespace std;
void printf(int* a, string str) {
    cout << str;
    for(int i = 0; i < 10; i++) {
        cout << a[i] <<" ";
    }
    cout << endl;
}
int i = 1;




//1. 堆排序
//1.1 堆初始化，从第一个非叶子节点开始，向前进行堆调整
void heap_init(int* a, int root, int len);
//1.2 堆调整，对于每个root，判断其孩子是否有比它大的，如果有，与之交换，并对交换后的下沉的root继续调整
void heap_adjust_part(int* a,int root, int len);
//堆排序主体函数，
// a. 先初始化堆，令最大值上浮至队首，且队列满足大根堆需求
// b. 交换队首队尾，提取出第一个最大值放至队尾，且对剩余len-1部分进行调整
// c. 调整堆，每调整一次都可以获取剩余最大值，回到b.
// c. 调整次数达到len -1 即可退出
void heap_sort(int* a, int len);


//2. 堆结构的上浮和下沉(插入和弹出)
//2.1 堆插入->插入新元素至队尾->上浮：从最后一个非叶子节点开始往上调整
int heap_insert(int* a, int num, int len);
//2.2 堆弹出->交换队首队尾->下沉: 对新交换过来的队首，往下调整，等同于堆排序的堆调整
int heap_pop(int *a, int len);


//3. 堆类的封装
class Heap_BigTop;







//1.1 堆初始化->
//  从第一个非叶子节点，令所有大值元素上浮
void heap_init(int* a, int root, int len) {
    for(int i = len / 2 - 1; i >= root; i--) {
        heap_adjust_part(a,i,len);
    }
}
void heap_adjust_part(int* a,int root, int len) { // 这个对应的是下沉操作
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



int heap_insert(int* a, int num, int len) { //插入，上浮，大根堆
    a[len] = num;   //把num直接放到队尾
    len++;  //多了一个元素，所以len++
    if (len == 1)   return len;
    int i = len / 2 - 1; //插入元素的 父节点索引
    int j = len - 1;    //插入元素的 索引
    /*
    if (a[i] >= a[j]) return len;   //num比父节点小，所以不需要上浮
    swap(a[i],a[j]);    //因为原来是满足堆的条件的，所以第一步只需要判断num和父节点二者大小关系即可
    i = i / 2 - 1;
    while(i >= 0) {
        if (a[i])
    }
     */
    while(i >= 0 && a[i] < a[j]) {
        swap(a[i],a[j]);
        j = i;
        i = (i - 1)/2;
    }
    return len;
}

int heap_pop(int *a, int len) { //大根堆下沉，弹出最小元素
    swap(a[0],a[len-1]);
    int root = 0;
    int lchild = root * 2 + 1;
    int flag = lchild;
    while(lchild < len - 1) {
        int rchild = root * 2 + 2;
        if (rchild < len - 1 && a[rchild] > a[lchild])
            flag = rchild;
        if (a[flag] > a[root]) {
            swap(a[root],a[flag]);
            root = flag;
            lchild = root * 2 + 1;
            flag = lchild;
        } else {
            return a[len - 1];
        }
    }
    return a[len - 1];

}


class Heap_BigTop {
    int* a;
    int size;
public:
    Heap_BigTop(){
        a = new int[100];
        size = 0;
    }
    Heap_BigTop(int n) {
        a = new int[n];
        size = 0;
    }
    ~Heap_BigTop() {
        delete[] a;
        a = nullptr;
    }
    //插入->上浮
    void insert(int num) {  //大根堆，直接在末尾插入，然后上浮
        size++;
        if (size == 1) {
            a[0]=num;
            return;
        }
        a[size - 1] = num;
        int child = size - 1;
        int root = (child - 1) / 2;
        while(root >= 0 && a[root] < a[child]) {
            swap(a[root],a[child]);
            child = root;
            root = (root - 1) / 2;
        }
    }
    //弹出->下沉
    int pop(){
        if (size == 0)  return -1;
        swap(a[0],a[size - 1]); //把要弹出的元素放到队尾，然后队首元素下沉
        size--;
        int root = 0;
        int lchild = 2 * root + 1;
        int flag = lchild;
        while(lchild < size) {
            int rchild = lchild + 1;
            if (rchild < size && a[rchild] > a[lchild])
                flag = rchild;
            if (a[flag] > a[root]) {
                swap(a[flag],a[root]);
                root = flag;
                lchild = root * 2 + 1;
                flag = lchild;
            } else {
                break;
            }
        }
        return a[size];
    }
    int top() { //栈顶元素为最大元素
        return a[0];
    }
};


struct UDF {
    bool operator()(const int& a, const int& b) const {
        return a < b;
    }
};




int main(){
    int a[10] = {112,112,107,128,121,118,105,113,106,116};
    printf(a,"原始数组: ");
    // 1. 堆排序测试代码
        //1.1 堆初始化
        //1.2 堆调整
    /*int len = 10;
    heap_sort(a,len);
    printf(a,"排序后: ");
    //heap_adjust_tree(a,0,len);
    //printf(a,"试一下：");
     */

    // 2. 优先队列测试代码
        // 2.1 队列逐个插入
        // 2.2 队列逐个弹出
    /*
    int * res= new int[10];
    for(int i = 0; i < 10; i++) {
        heap_insert(res,a[i],i);
    }
    printf(res,"insert: ");
    cout << "pop  : ";
    for(int i = 0; i < 10; i++) {
        cout << heap_pop(res,10 - i) << " ";
    }
    //printf(res,"after heap insert: ");
     */

    // 3. 优先队列类封装
        // 3.1 优先队列插入
        // 3.2 优先队列弹出
    Heap_BigTop res(100);
    for(int i = 0; i < 10; i++) {
        res.insert(a[i]);

    }
    for(int i = 0; i < 10; i++) {
        cout << res.pop() << " ";
    }
    cout << endl;

    //greater -> ">" -> 越来越大 -> 升序 -> 最开始弹出的是小的 -> 小根堆
    priority_queue<int,vector<int>,greater<int> > q; //小根堆，greater() 返回的是a > b, top弹出是升序排列

    //less -> "<" -> 越来越小 -> 降序 -> 最开始弹出的是大的 —> 大根堆
    priority_queue<int,vector<int>,less<int> > q_; //大根堆，less() 返回的是 a < b, top弹出是降序排列

    //自己定义结构体的()操作， < 降序大根， > 升序小根
    priority_queue<int,vector<int>,UDF > q_u; //自己定义的 < 就是升序排列(大根堆)， > 是降序排列(小根堆)
    for(int i = 0; i < 10; i++) {
        q.push(a[i]);
        q_.push(a[i]);
        q_u.push(a[i]);
    }
    for(int i = 0; i < 10; i++) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    for(int i = 0; i < 10; i++) {
        cout << q_.top() << " ";
        q_.pop();
    }
    cout << endl;
    for(int i = 0; i < 10; i++) {
        cout << q_u.top() << " ";
        q_u.pop();
    }
    return 0;
}