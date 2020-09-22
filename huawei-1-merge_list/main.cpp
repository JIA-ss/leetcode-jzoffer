#include <iostream>
#include <vector>

using namespace std;
//题目是，给一个链表排序，要求O(nlog(n)) O(1)
struct Node {
    int val;
    Node* next;
    Node(int v):val(v),next(nullptr){}
};

Node* getByIdx(Node* root, int i) {
    if (i == 0) return root;
    while(i) {
        root = root->next;
        i--;
    }
    return root;
}

Node* findMid(Node* root) {
    if (root == nullptr || root->next == nullptr)
        return root;
    Node* opt = root;
    int count = 0;
    while(opt) {
        opt = opt->next;
        count++;
    }
    int len = (count-1) / 2 ;
    while(len) {
        root = root->next;
        len--;
    }
    return root;
}

Node* merge(Node* L, Node* R) {
    if (L == nullptr)   return R;
    if (R == nullptr)   return L;
    if (L->val > R->val) {
        swap(L,R);
    }
    Node* res = L;
    Node* L_pre = L;
    Node* R_pre = R;
    while(L != nullptr && R != nullptr) {
        while(L != nullptr && L->val <= R->val) {
            L_pre = L;
            L = L->next;
        }
        if (L == nullptr) {
            L_pre->next = R;
            return res;
        }
        Node* R_flag = R;
        while(R != nullptr && R->val <= L->val) {
            R_pre = R;
            R = R->next;
        }
        L_pre->next = R_flag;
        R_pre->next = L;
    }
    return res;
}

Node* mergeSort(Node* root) {
    if (root == nullptr || root->next == nullptr) {
        return root;
    }
    Node* M = findMid(root);
    Node* R = M->next;
    M->next = nullptr;
    Node* L = mergeSort(root);
    R = mergeSort(R);

    return merge(L,R);

}


//合并两个有序链表
Node* merge_(Node* L, Node* R);

Node* mergesort(Node* root) {
    //定义跳出条件
    if(root == nullptr || root->next == nullptr) {
        return root;
    }
    Node* M = findMid(root);
    Node* R = M->next;
    M->next = nullptr;
    Node* L = mergesort(root);
    R = mergesort(R);
    //就此，我们可以认为，得到了两个有序链表，L和R，只需要合并即可
    Node* res = merge_(L,R);
    return res;
}

Node* merge_(Node* L, Node* R) {
    if (L == nullptr)   return R;
    if (R == nullptr)   return L;
    if (L->val > R->val)    swap(L,R);
    Node* res = L;
    Node* L_pre = L;
    Node* R_pre =R;
    while(L != nullptr && R != nullptr) {
        //先找到一个，L的比R大的第一个元素
        while(L != nullptr && L->val <= R->val) {
            L_pre = L;
            L = L->next;
        }
        //如果没有，则直接把R接到L后面退出即可
        if(L == nullptr) {
            L_pre->next = R;
            return res;
        }
        // 找到比现在的L大的第一个元素
        // 从R开始，到该元素的这段，插入到L_pre 和 L中间
        Node* R_ori = R;
        while(R != nullptr && R->val <= L->val) {
            R_pre = R;
            R = R->next;
        }
        L_pre->next = R_ori;
        R_pre->next = L;
    }
    return res;
}

void print(Node* root) {
    while(root) {
        cout << root->val <<" ";
        root = root->next;
    }
    cout << endl;
}

int main(){

    Node* root = new Node(4);
    root->next = new Node(10);
    root->next->next = new Node(-3);
    root->next->next->next = new Node(8);
    root->next->next->next->next = new Node(6);
    print(root);
    root = mergesort(root);
    print(root);
    return 0;
}
