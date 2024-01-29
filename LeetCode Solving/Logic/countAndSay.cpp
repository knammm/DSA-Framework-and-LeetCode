class Solution {
public:
    string output = "";
    string say = "";
    
    void solve(int n){
        if(n == 1){
            output += "1";
        }
        else{
            solve(n - 1);
            int count = 0;
            if(output.length() == 1){
                count = 1;
                say += count + '0';
                say += output;
            }
            else{
                for(int i = 0; i < output.length(); i++){
                    if(output[i] == output[i + 1]){
                        count++;
                    }
                    else{
                        count++;
                        say += count + '0';
                        say += output[i];
                        count = 0;
                    }
                }
            }
            output = say;
            say = "";
        }
    }

    string countAndSay(int n) {
        solve(n);
        return output;
    }
};