// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include "bits/stdc++.h"

int solution(vector<int> &A) {
    // Implement your solution here
    unordered_map<int, int> map;
    for(int i = 0; i < (int)A.size(); i++){
        map[A[i]]++;
    }
    for(auto& it:map){
        if(it.second % 2 != 0) return it.first;
    }
    return -1;
}