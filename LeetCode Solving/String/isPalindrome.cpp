class Solution {
public:
    bool isPalindrome(string s) {
        std::string result = "";
        int l = s.length();
        for(int i = 0; i < l; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                result += s[i];
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                char c = s[i] + (97 - 65);
                result += c;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                result += s[i];
            }
        }
        bool flag = 1;
        int len = result.length();
        for(int i = 0; i < (len / 2); i++){
             if(result[i] != result[len - 1 - i]){
                 flag = 0;
                 break;
             }
        }
        if(flag) return 1;
        else return 0;
    }
};