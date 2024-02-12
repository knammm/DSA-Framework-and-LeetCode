class Solution {
public:
    string decimalToBinary(int dec, int length){
        int binaryNum[20] = {0};
        int i = 0;
        while(dec > 0){
            binaryNum[i] = dec % 2;
            dec /= 2;
            i++;
        }
        string s = "";
        for(int i = length - 1; i >= 0; i--){
            s += '0' + binaryNum[i];
        }
        return s;
    }
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        int maxPowerTwo = pow(2, k);
        for(int i = 0; i <= maxPowerTwo; i++){
            string binaryString = decimalToBinary(i, k);
            if(s.find(binaryString) == -1){
                return false;
            }
        }
        return true;
    }
};