// When we use iterator => use it as a pointer.
// To access the key or value => it->first or it->second

#include <iostream>
#include "bits/stdc++.h"
using namespace std;

vector<int> solution(vector<string> s){
    int N = s.size();
    int M = s[0].length();
    vector<int> result;
    // 2D array
    // row is N, col is M. We will check each column to meet the same char
    for(int i = 0; i < M; i++){
        unordered_map<char, int> map;
        for(int j = 0; j < N; j++){
            unordered_map<char, int>::iterator it = map.find(s[j][i]);
            if(it != map.end()){
                // i => index of letter in string
                // *it.second => index of prevString, j is index of newString
                result.push_back(i);
                result.push_back(j);
                result.push_back(it->second);
                return result;
            }
            map[s[j][i]] = j; // store prevString index
        }
    }
    return result;
}

int main()
{
    vector<int> a = solution({"bdafg", "ceagi"});
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    return 0;
}