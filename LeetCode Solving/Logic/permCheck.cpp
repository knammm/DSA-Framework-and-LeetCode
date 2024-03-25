// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    sort(A.begin(), A.end());
    int check = 1;
    for(int i = 0; i < (int)A.size(); i++){
        if(A[i] == check) check++;
        else return 0;
    }
    return 1;
}