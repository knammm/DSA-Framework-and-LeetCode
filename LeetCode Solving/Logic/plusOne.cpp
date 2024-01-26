class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carryOut = 0;
        int size = digits.size();
        digits[size - 1] += 1;
        if(digits[size - 1] == 10){
            digits[size - 1] = 0;
            carryOut = 1;
        }
        int index = size - 2;
        while(carryOut != 0 && index != -1){
            digits[index]++;
            if(digits[index] == 10){
                digits[index] = 0;
                carryOut = 1;
            }
            else{
                carryOut = 0;
            }
            index--;
        }
        vector<int> newVec;
        if(carryOut == 1){
            newVec.push_back(1);
            for(int i = 0; i < digits.size(); i++){
                newVec.push_back(digits[i]);
            }
            return newVec;
        }
        return digits;
    }
};