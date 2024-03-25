// you can use includes, for example:
// #include <algorithm>
#include "bits/stdc++.h"

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    unordered_map<int, int> map;
    int size = A.size();
    for(int i = 0; i < size; i++){
        map[A[i]]++;
        if(map[A[i]] > (size / 2)) return i;
    }
    return -1;
}