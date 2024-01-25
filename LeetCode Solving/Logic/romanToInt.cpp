class Solution {
public:
    int returnIndexChar(char c){
        char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        for(int i = 0; i < 7; i++){
            if(c == roman[i]){
                return i;
            }
        }
        return -1;
    }
    int romanToInt(string s) {
        int map[7] = {1, 5, 10, 50, 100, 500, 1000};
        int total = 0;
        int length = s.length();
        for(int i = 0; i < length - 1; i++){
            int indexChar = returnIndexChar(s[i]);
            int indexNextChar =returnIndexChar(s[i + 1]);
            if(map[indexChar] < map[indexNextChar]){
                total -= map[indexChar];
            }
            else{
                total += map[indexChar];
            }
        }
        int lastIdx = returnIndexChar(s[length - 1]);
        total += map[lastIdx];
        return total;
    }
};