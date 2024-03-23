#include "bits/stdc++.h"

int solution(vector<int>& blocks){
	int size = blocks.size();
	int maxJump = 0;
	// Idea: iterate at each element. Check back and front => max distance
	for(int i = 0; i < size; i++){
		int backward = i;
		int forward = i;
		int distance = 0;
		while(blocks[backward - 1] >= blocks[backward] && backward - 1 >= 0){
			backward--;
		}
		while(blocks[forward + 1] >= blocks[forward] && forward + 1 <= size - 1){
			forward++;
		}
		if(backward < 0) backward = 0;
		if(forward > size - 1) forward = size - 1;
		maxJump = max(maxJump, forward - backward + 1);
	}
	return maxJump;
}