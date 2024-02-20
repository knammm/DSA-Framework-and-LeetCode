class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = '\0';
        for(int i = 0; i < s.length(); i++){
            c ^= s[i];
            c ^= t[i];
        }
        c ^= t[(int)t.length() - 1];
        return c;
    }
};