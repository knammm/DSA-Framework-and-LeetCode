class Solution {
public:
    string subString(string s, int start, int length){
        int maxLength = s.length();
        string returnString = "";
        if(start + length > maxLength) {
            return "\0";
        }
        for(int i = start; i < start + length; i++){
            returnString += s[i];
        }
        return returnString;
    }
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        for(int i = 0; i < len1 - len2 + 1; i++){
            if(subString(haystack, i, len2) == needle){
                return i;
            }
        }
        return -1;
    }
};