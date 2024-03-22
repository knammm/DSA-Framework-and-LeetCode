// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include "bits/stdc++.h"

int solution(int N) {
    // Implement your solution here
    int count = 0;
    int check = 0;
    bool flag = 0;
    while(N > 0){
        if(N % 2 == 1 && !flag){
            flag = 1;
        }
        if(N % 2 == 0 && flag){
            check++;
            count = max(count, check);
        }
        if(N % 2 == 1){
            count = max(count, check);
            check = 0;
        }
        N = N / 2;
    }
    return count;
}