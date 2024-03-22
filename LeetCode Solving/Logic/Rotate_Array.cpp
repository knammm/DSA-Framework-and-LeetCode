// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // Implement your solution here
    int size = A.size();
    if(size <= 1) return A;
    int real_rotate = K % size;
    for(int i = 0; i < real_rotate; i++){
        int lastNum = A[size - 1];
        for(int j = size - 1; j >= 1; j--){
            A[j] = A[j - 1];
        }
        A[0] = lastNum;
    }
    return A;
}