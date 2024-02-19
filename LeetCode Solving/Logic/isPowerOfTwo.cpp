class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return 1;
        bool flag = 0;
        while(n > 1 && n % 2 == 0){
            flag = 1;
            if(n % 2 != 0){
                flag = 0;
                break;
            }
            n = n / 2;
        }
        if(flag == 1 && n == 1) return 1;
        else return 0;
    }
};