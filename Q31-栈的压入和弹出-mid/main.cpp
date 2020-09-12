#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    stack<int> q;
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size())  return false;
        if(pushed.size() == 0)  return true;
        int i = 0, j = 0;
        while (j < popped.size()) {
            if (i == pushed.size()) {
                if (q.empty() || q.top() != popped[j])  return false;
                q.pop();
                j++;
            }
            else if (pushed[i] == popped[j]) {
                i++;
                j++;
            } else {
                if (!q.empty() && q.top() == popped[j]) {
                    q.pop();
                    j++;
                } else {
                    q.push(pushed[i++]);
                }
            }
        }
        return true;

    }
};


int main() {
    Solution s;
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};
    cout << s.validateStackSequences(pushed,popped);
    return 0;
}
