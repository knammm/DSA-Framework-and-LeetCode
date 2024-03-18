class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int result = -1;
        for(int i = 0; i < s.length() - 1; i++){
            int sameCharPos = -1;
            for(int j = i + 1; j < s.length(); j++){
                if(s[i] == s[j]) sameCharPos = j;
            }
            if((sameCharPos != -1) && (result < sameCharPos - i - 1)) result = sameCharPos - i - 1;
        }
        return result;
    }
};