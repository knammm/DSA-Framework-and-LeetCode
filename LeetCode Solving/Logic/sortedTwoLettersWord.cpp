#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int solution(string s){
    int minDel = 0;
    int numB = 0;
    // We just care about B compare it. numB is how many B since we met.
    // When we meet A, just sum up minDel to 1 and compare to total B we have.
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'A'){
            minDel = min(numB, minDel + 1);
        }   
        else numB++;
    }
    return minDel;
}

int main()
{
    std::cout<<solution("AAABAAABBBBBABBBBBA");

    return 0;
}