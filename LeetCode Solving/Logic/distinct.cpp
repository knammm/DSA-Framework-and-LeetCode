// you can use includes, for example:
// #include <algorithm>
#include <set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    set<int> mySet;
    for(int i = 0; i < (int)A.size(); i++){
        mySet.insert(A[i]);
    }
    return mySet.size();
}