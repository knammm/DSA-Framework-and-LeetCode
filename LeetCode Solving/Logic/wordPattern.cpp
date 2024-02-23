class Solution {
public:
    bool wordPattern(string pattern, string s) {
        set<char> diffChar;
        set<string> diffWord;
        unordered_map<char, string> map;
        int i = 0;
        string word = "";
        int k = 0;
        // Find word and append to set
        while(s[i] != '\0'){
            if(s[i] != ' '){
                word += s[i];
            }
            else{
                diffWord.insert(word);
                map[pattern[k]] = word;
                word = "";
                k++;
            }
            i++;
        }
        // Last word processing
        map[pattern[k]] = word;
        diffWord.insert(word);
        // Checking string
        string check = "";
        for(int j = 0; j < pattern.length() - 1; j++){
            diffChar.insert(pattern[j]); // Insert the char of the pattern to set
            check += map[pattern[j]];
            check += ' ';
        }
        // Last char and word processing
        diffChar.insert(pattern[pattern.length() - 1]);
        check += map[pattern[pattern.length() - 1]];
        // 2 case return => size and same string
        if(diffChar.size() != diffWord.size()) return 0;
        return check == s;
    }
};