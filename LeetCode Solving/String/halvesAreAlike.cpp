class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    bool halvesAreAlike(string s) {
        int count1 = 0;
        int midIndex = s.length() / 2;
        for(int i = 0; i < midIndex; i++){
            if(isVowel(s[i])) count1++;
            if(isVowel(s[i + midIndex])) count1--;
        }
        return count1 == 0;
    }
};