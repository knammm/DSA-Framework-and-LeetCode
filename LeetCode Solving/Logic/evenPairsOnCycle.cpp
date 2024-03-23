#include "bits/stdc++.h"

int solution(vector<int>& A){
	int count = 0;
	int size = A.size();
	bool flag = 0;
	for(int i = 0; i < size - 1; i++){
		if((A[i] + A[i + 1]) % 2 == 0) {
			count++;
			if(i == size - 2) flag = 1;
			i++;
		}
	}
	if((A[0] + A[size - 1]) % 2 == 0 && !flag) count++;
	return count;
}