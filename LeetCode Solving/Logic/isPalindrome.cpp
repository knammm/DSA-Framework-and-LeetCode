class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int temp = x;
        long long int revNum = 0;
        while(x){
            int remain = x % 10;
            revNum = revNum * 10 + remain;
            x = x / 10;
        }
        if(revNum == temp){
            return true;
        }
        else{
            return false;
        }
    }
};