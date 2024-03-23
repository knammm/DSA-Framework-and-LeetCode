#include "bits/stdc++.h"

int solution(vector<int>& X, vector<int>& Y){
	vector<int> vec = X;
	std::sort(vec.begin(), vec.end());
	int gap = 0;
	for(int i = vec.size() - 1; i > 0; i--){
		gap = max(gap, abs(vec[i] - vec[i - 1]));
	}
	return gap;
}