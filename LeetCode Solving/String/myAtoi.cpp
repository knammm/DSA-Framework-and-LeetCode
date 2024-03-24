class Solution {
public:
    int myAtoi(string s) {
        if(s == "") return 0;
        string convert = "";
        bool flagSign = 0;
        long long num = 0;
        long long checkMAX = INT_MAX;
        checkMAX += 1;
        int i = 0;
        // 1. ignore space
        while(s[i] == ' '){
            i++;
        }
        // 2. sign check
        if((s[i] == '+' || s[i] == '-') && (i < s.length())){
            convert += s[i];
            i++;
        }
        while(s[i] >= '0' && s[i] <= '9' && (i < s.length())){
            convert += s[i];
            i++;
        }
        if(convert == "+" || convert == "-") return 0;
        // 3. skip sign
        if(convert[0] == '+' || convert[0] == '-'){
            i = 1;
            if(convert[0] == '-') flagSign = 1;
        }
        else i = 0;
        // 4. convert
        while(convert[i] != '\0'){
            num *= 10;
            if(num > checkMAX) break; // out of range => no need to check more
            num += convert[i] - '0';
            i++;
        }
        // 5. add sign
        if(flagSign) num = -num;
        // 6. check range
        if(num < INT_MIN) num = INT_MIN;
        else if(num > INT_MAX) num = INT_MAX;
        return num;
    }
    
};