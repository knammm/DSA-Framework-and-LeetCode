class Solution {
public:
    string reverseString(string s){
        string rev = "";
        int lengthS = s.length();
        for(int i = lengthS - 1; i >= 0; i--){
            rev += s[i];
        }
        return rev;
    }

    string addBinary(string a, string b) {
		// Idea: Using merge method then reverse
        string reverse = "";
        int lastA = a.length() - 1;
        int lastB = b.length() - 1;
        int carryOut = 0;
        while(lastA >= 0 && lastB >= 0){
            if(a[lastA] == '0' && b[lastB] == '0'){
                if(carryOut == 1){
                    reverse += "1";
                    carryOut = 0;
                }
                else{
                    reverse += "0";
                }
            }
            else if((a[lastA] == '0' && b[lastB] == '1') || (a[lastA] == '1' && b[lastB] == '0')){
                if(carryOut == 1){
                    reverse += "0";
                    carryOut = 1;
                }
                else{ 
                    reverse += "1";
                }
            }
            else{
                if(carryOut == 1){
                    reverse += "1";
                    carryOut = 1;
                }
                else{
                    reverse += "0";
                    carryOut = 1;
                }
            }
            lastA--;
            lastB--;
        }

        while(lastA >= 0){
            if(a[lastA] == '0'){
                if(carryOut == 1){
                    reverse += "1";
                    carryOut = 0;
                }
                else{
                    reverse += "0";
                }
            }
            else{
                if(carryOut == 1){
                    reverse += "0";
                    carryOut = 1;
                } 
                else{
                    reverse += "1";
                }
            }
            lastA--;
        }

        while(lastB >= 0){
            if(b[lastB] == '0'){
                if(carryOut == 1){
                    reverse += "1";
                    carryOut = 0;
                }
                else{
                    reverse += "0";
                }
            }
            else{
                if(carryOut == 1){
                    reverse += "0";
                    carryOut = 1;
                } 
                else{
                    reverse += "1";
                }
            }
            lastB--;
        }

        if(carryOut == 1){
            reverse += "1";
        }

        string result = reverseString(reverse);
        return result;
    }
};