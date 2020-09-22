# 09.22华为面试题目1
对链表进行排序，要求时间复杂度`O(nlogn)`,空间复杂度`O(1)`

> 很明显，使用归并排序，但是需要原地merge \
> 当时没做出来，因为思路不明确，卡在了原地merge上

```c++
//找到root的中间节点
Node* findMid(Node* root);
//合并两个有序链表
Node* merge(Node* L, Node* R); 

Node* mergesort(Node* root) {
    //定义跳出条件
    if(root == nullptr || root->next == nullptr) {
        return root;
    }
    Node* M = findMid(root);
    Node* R = M->next;
    M->next = nullptr;
    //左半边开始递归
    Node* L = mergesort(root);
    //右半边递归
    R = mergesort(R);
    //就此，我们可以认为，得到了两个有序链表，L和R，只需要合并即可
    Node* res = merge(L,R);
    return res;
}

Node* merge(Node* L, Node* R) {
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
```