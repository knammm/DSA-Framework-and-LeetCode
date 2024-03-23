#include "bits/stdc++.h"

int solution(string s){
	int numA, numB, numN = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'A') numA++;
		else if(s[i] == 'B') numB++;
		else if(s[i] == 'N') numN++;
		else continue;
	}
	int result = 0;
	while(numA >= 3 && numB >= 1 && numN >= 2){
		numA -= 3;
		numB -= 1;
		numN -= 2;
		result++;
	}
	return result;
}