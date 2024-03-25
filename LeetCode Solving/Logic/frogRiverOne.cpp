// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // Implement your solution here
	// Create a vector of leaves
    vector<int> vec(X + 1, -1);
    int size = A.size();
    for(int i = 0; i < size; i++){
        if(vec[A[i]] == -1) vec[A[i]] = i; // change as the fastest arrive. When meet again => no change
    }
	// Start from 1st leaf
    int maxTime = vec[1];
    for(int i = 1; i < (int)vec.size(); i++){
        if(vec[i] == -1) return -1; // can not jump here
        if(vec[i] > maxTime) maxTime = vec[i];
    }
    return maxTime;
}