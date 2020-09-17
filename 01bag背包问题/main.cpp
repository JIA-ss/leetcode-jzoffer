#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bag_0_1_question(int products_count,int capacity,vector<int> &weights,vector<int> &values) {
    vector<vector<int> > res(products_count + 1, vector<int>(capacity + 1, 0));
    for(int i = 1; i <= products_count; i++) {
        for(int j = 1; j <= capacity; j++) {
            if(weights[i - 1] > j) { //当容量不足，必然无法放第i个物品, 注意第i个物品的重量是weights[i-1]，同理values[i-1] 这是一个大坑
                res[i][j] = res[i-1][j];
            } else {
                res[i][j] = max(res[i-1][j],res[i-1][j-weights[i - 1]] + values[i - 1]);
            }
        }
    }
    return res[products_count][capacity];
}

int bag_0_1_question_1D(int products_count,int capacity,vector<int>& weights,vector<int> values){
    vector<int> res(capacity + 1, 0);
    for(int i=1;i<=products_count;++i){
        for(int j = weights[i-1]; j <= capacity; j++){//注意j必须从capacity开始
            cout << i <<"," << j << "    " << weights[i-1] << "," << values[i - 1] << endl;
            cout << "res[j-weights[i - 1]]+values[i - 1] = " << res[j-weights[i - 1]]+values[i - 1] << endl;
            cout << "res[j] = " << res[j] << endl;
            res[j] = max(res[j-weights[i - 1]]+values[i - 1],res[j]);
            cout <<"res[j] = " << res[j] << endl;
            //cout << j << ":" << res[j] << endl;
        }
    }

    cout << endl;
    for(int i = 0; i < capacity + 1; i++) cout << res[i] << " ";
    cout << endl;

    return res[capacity];
}




int main() {
    vector<int> w = {2,2,6,6,6,2,2,2};
    vector<int> v = {5,5,8,8,8,10,10,10};
    int products_count = w.size();
    int capacity = 10;
    cout << bag_0_1_question(products_count,capacity,w,v) << endl;
    cout << bag_0_1_question_1D(products_count,capacity,w,v) << endl;
    return 0;
}
