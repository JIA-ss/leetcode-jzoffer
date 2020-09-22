#include <iostream>
#include <vector>
using namespace std;

char toAZ(char& idx) {
    if (idx == 'Z' + 1) {
        idx = 'A';
    }
    return idx;
}

int main(){
    int M,N;
    cin>> M >> N;
    int top = 0;
    int bottom = M-1;
    int left = 0;
    int right = N-1;
    char idx = 'A';
    vector<vector<char> > res(M,vector<char>(N,'A'));
    while(top < bottom && left < right) {
        for(int i = left; i <= right; i++) {
            res[top][i] = toAZ(idx++);
        }
        for(int i = top + 1; i <= bottom; i++) {
            res[i][right] = toAZ(idx++);
        }
        for(int i = right - 1; i >= left; i++) {
            res[bottom][i] = toAZ(idx++);
        }
        for(int i = bottom - 1; i >= top + 1; i--) {
            res[i][left] = toAZ(idx++);
        }
        top--;
        bottom++;
        left++;
        right--;
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cout << res[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}