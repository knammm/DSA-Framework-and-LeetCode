// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // Implement your solution here
	// Idea: Update max and min.
	// Finally, update the counter that less than min into min.
    int curr_min = 0;
    int curr_max = 0;
    int size = A.size();
    vector<int> result(N, 0);
    for(int i = 0; i < size; i++){
        if(1 <= A[i] && A[i] <= N){
            int X = A[i] - 1;
            if(result[X] < curr_min) result[X] = curr_min; // set back to min if less than
            result[X]++;
            if(curr_max < result[X]) curr_max = result[X]; // update max
        }
        else if(A[i] == N + 1){
			// Operation: Change all to max => min now equal to max
            curr_min = curr_max;
        }
    }
    for(int i = 0; i < N; i++){
        if(result[i] < curr_min) result[i] = curr_min;
    }
    return result;
}