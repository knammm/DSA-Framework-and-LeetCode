// abbaa => bbaaa => baaab => aaabb => aabba => abbaa(not count)

#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int solution(string s){
    int count = 0;
    int size = s.length();
    if(s[0] == s[size - 1]) count++;
    for(int i = 0; i < size - 1; i++){
        if(s[i] == s[i + 1]) count++;
    }
    return count;
}

int main()
{
    std::cout<<solution("abbaa") << endl;
    std::cout << solution("aaaa") << endl;
    cout << solution("abab") << endl;

    return 0;
}