// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
	// Target: return the number that is not exist in the Array given that Array miss 1 element in order.
        int result = 1;
        sort(A.begin(), A.end());
        for(int i = 0; i < (int)A.size(); i++){
            if(result == A[i]) result++;
            else if(result < A[i]) return result;
        }
        return result;
}
