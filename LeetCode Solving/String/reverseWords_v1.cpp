class Solution {
public:
    string removeSpace(string s){
        int l = s.length() - 1;
        string result = "";
        int index = 0;
        while(s[index] == ' '){
            index++;
        }
        while(s[l] == ' '){
            l--;
        }
        for(int i = index; i <= l; i++){
            result += s[i];
        }
        for(int i = 0; i < result.length(); i++){
            if(result[i] == ' ' && result[i + 1] == ' '){
                for(int j = i + 1; j < result.length() - 1; j++){
                    result[j] = result[j + 1];
                }
                i--;
                result[result.length() - 1] = '\0';
            }
        }
        int k = 0;
        string real = "";
        while(result[k] != '\0'){
            real += result[k];
            k++;
        }
        return real;
    }
    string reverseWords(string s) {
        string newS = removeSpace(s);
        string words[800] = {"\0"};
        string word = "";
        int k = 0;
        for(int i = 0; i < newS.length(); i++){
            if(newS[i] != ' ' && newS[i] != '\0'){
                word += newS[i];
            }
            else{
                words[k] = word;
                k++;
                word = "";
            }
        }
        words[k] = word;
        k++;
        string result = "";
        for(int i = k - 1; i > 0; i--){
            result += words[i];
            result += ' ';
        }
        result += words[0];
        return result;
    }
};