// you can use includes, for example:
#include "bits/stdc++.h"

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    long long sum = 0;
    int size = A.size();
    for(int i = 0; i < size; i++){
        sum += A[i];
    }
    int leftSum = 0;
    int result = INT_MAX;
    int p = 1;
    for(int i = 0; i < size && p < size; i++){
        leftSum += A[i];
        int rightSum = sum - leftSum;
        result = min(result, abs(leftSum - rightSum));
        p++;
    }
    return result;
}