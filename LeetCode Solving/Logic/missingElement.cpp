// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    long long result = 0;
    int size = A.size();
    for(int i = 0; i < size; i++){
        result ^= A[i];
        result ^= (i + 1);
    }
    result ^= size + 1;
    return result;
}