#include "bits/stdc++.h"

int solution(vector<int> A){
	int segments = A.size();
	int i = 0;
	int count = 0;
	// Left edge
	while(A[i] == A[i + 1] && i < segments - 1){
		i++;
	}
	count++;
	// Case the same
	if(i == segments - 1) return count;
	// Right edge
	int j = segments - 1;
	while(A[j] == A[j - 1]){
		j--;
	}
	count++;
	// Flag for hill and valley
	bool flag_hill = 0;
	bool flag_valley = 0;
	for(int i = 0; i < j; i++){
		if(A[i] < A[i+1]){
			if(!flag_hill) flag_hill = 1;
			if(flag_valley){
				// Valley position detected
				count++;
				flag_valley = 0;
			}
		}
		else if(A[i] > A[i+1]){
			if(!flag_valley) flag_valley = 1;
			if(flag_hill){
				// Hill position detected
				count++;
				flag_hill = 0;
			}
		}
		else continue;
	}
	return count;
}