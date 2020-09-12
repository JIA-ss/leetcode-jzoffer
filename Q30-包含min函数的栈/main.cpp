#include <iostream>
struct ListEle {
    int val;
    int min;
    ListEle* down;
    ListEle(int v, int m, ListEle* l):val(v),min(m),down(l){}
};
class MinStack {
public:
    ListEle* top_ele;
    /** initialize your data structure here. */
    MinStack() {
        top_ele = nullptr;
    }

    void push(int x) {
        if(top_ele == nullptr) {
            top_ele = new ListEle(x,x,nullptr);
        } else {
            int min_ = x < top_ele->min ? x : top_ele->min;
            auto new_list = new ListEle(x,min_,top_ele);
            top_ele = new_list;
        }
    }

    void pop() {
        auto down_ = top_ele->down;
        delete top_ele;
        top_ele = down_;
    }

    int top() {
        return top_ele->val;
    }

    int min() {
        return top_ele->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
int main() {
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    s.min();
    s.pop();
    s.top();
    s.min();
    return 0;
}
