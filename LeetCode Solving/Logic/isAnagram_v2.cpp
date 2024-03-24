class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> chars(26, 0);
        int length1 = s.length();
        int length2 = t.length();
        if(length1 != length2) return false;
        for(int i = 0; i < length1; i++){
            chars[s[i] - 'a']++;
            chars[t[i] - 'a']--;
        }
        for(int i = 0; i < chars.size(); i++){
            if(chars[i] != 0) return false;
        }
        return true;
    }
};