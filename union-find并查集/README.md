# 并查集
给你一个二维数组`M`,`M[i][j]`表示i和j的关系，让你查找关系圈的个数 \


> 并查集主要包括
> 1. union(i,j)
> 2. find(i)

```c++
vector<int> relation(M.size(),0); //声明一个用于储存最终集合的数


for(int i = 0; i < M.size(); i++)   relation[i] = i;    //初始化关系网，每个人的leader都是自己
for(int i = 0; i < M.size(); i++) {
    for(int j = 0; j < M[0].size(); j++) {
        if(i != j && M[i][j] == 1)  union(i,j);
    }
}

int count = 0;
for(int i = 0; i < M.size(); i++) {    
    if(relation[i] == i)    count++;
}

//查找集合，并进行路径压缩
int find(int i) {
    int i_root = relation[i];
    if(i_root == i) return i;
    relation[i] = find(i_root);
    return relation[i];
}

void union(int i, int j) {    
    int iroot = find(i);
    int jroot = find(j);
    if (iroot != jroot) relation[iroot] = jroot;
}


```