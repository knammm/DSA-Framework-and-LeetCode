class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(int i = 0; i < columnTitle.length(); i++){
            int order = columnTitle[i] - 'A' + 1; // get the order number
            result = result * 26 + order; // 26 words
        }
        return result;
    }
};