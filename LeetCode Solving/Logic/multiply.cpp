class Solution {
public:
    char numToChar(int n){
        char c = '0' + n;
        return c;
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        // Assign 0 to every element
        vector<int> arr(num1.length() + num2.length(), 0);

        for(int i = num1.length() - 1; i >= 0; i--){
            for(int j = num2.length() - 1; j >= 0; j--){
                arr[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                arr[i + j] += arr[i + j + 1] / 10; // Carry Number if > 10
                arr[i + j + 1] %= 10;
            }
        }

        int cursor = 0;
        while(arr[cursor] == 0){
            ++cursor;
        }
        string ans = "";
        for(int i = cursor; i < arr.size(); i++){
            ans += numToChar(arr[i]);
        }
        return ans;
    }
};