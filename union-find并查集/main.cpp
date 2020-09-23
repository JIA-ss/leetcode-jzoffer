#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    //relation代表合并后的集合
    vector<int> relation;
    int find_leader(int i) {
        //如果i的直接leader是自身，那么i就是这个集合的总leader
        int i_direct_leader = relation[i];
        if (i_direct_leader == i) {
            return i;
        }
        //如果不是，需要进行路径压缩，把i的直接leader设定为集合的最高leader
        relation[i] = find_leader(i_direct_leader);
        return relation[i];

    }

    void union_relation(int i, int j) {
        int iroot = find_leader(i);
        int jroot = find_leader(j);
        //如果i和j的leader不是一个人，那么把i和j的集合合并起来
        if (iroot != jroot) {
            relation[iroot] = jroot;
        }
    }
    int findCircleNum(vector<vector<int>>& M)
    {
        relation.assign(M.size(),0);
        for(int i = 0; i < M.size(); ++i)
            relation[i] = i;
        for(int i = 0; i < M.size(); ++i) {
            for(int j = 0; j < M[0].size(); ++j) {
                if (i != j && M[i][j] == 1) {
                    union_relation(i,j);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < M.size(); i++) {
            if (relation[i] == i) {
                count++;
            }
        }
        return count;

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
