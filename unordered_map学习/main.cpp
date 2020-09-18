#include <iostream>
#include <unordered_map>
using namespace std;

//
struct P {
    int a;
    int b;
    bool operator==(const P& p) const {
        return this->a == p.a;
    }
};


struct P_Hash {
    size_t operator()(const P& p) const {
        return p.a % 10;
    }
};


int main() {
    unordered_map<P,bool,P_Hash> mp;
    P tmp;
    tmp.a = 1;
    tmp.b = 2;
    P tmp2;
    tmp2.a = 3;
    tmp2.b = 3;
    mp[tmp] = 2;
    mp[tmp2] = 5;
    //mp.clear();
    cout << mp[tmp2];
    return 0;
}
