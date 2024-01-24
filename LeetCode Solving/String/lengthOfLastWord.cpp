class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        if(s == "\0") {
            return 0;
        }
        if(s.find(" ") == -1){
            return length;
        }
        
        int numLastSpace = 0;
        int index = length - 1;
        while(s[index] == ' '){
            numLastSpace += 1;
            index--;
        }
        
        int maxSpace = 0;
        bool flag = false;
        for(int i = 0; i < length; i++){
            if(s[i] == ' ' && (i < length - numLastSpace - 1)){
                maxSpace = i;
                flag = true;
            }
        }
        int indexT = 0;
        if(maxSpace != 0 || flag == true){
            indexT = maxSpace + 1;
        }
        int lastLength = length - indexT - numLastSpace;
        return lastLength;
    }
};