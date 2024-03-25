// you can use includes, for example:
#include "bits/stdc++.h"

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    int checkNum = 1;
    std::sort(A.begin(), A.end());
    for(int i = 0; i < (int)A.size(); i++){
        if(A[i] == checkNum) checkNum++;
        else if(A[i] > checkNum) return checkNum;
    }
    return checkNum;
}