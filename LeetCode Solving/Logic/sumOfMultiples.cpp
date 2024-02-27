class Solution {
public:
    bool isDivisible(int n){
        if(n % 3 == 0 || n % 5 == 0 || n % 7 == 0) return 1;
        return 0;
    }
    int sumOfMultiples(int n) {
        int sum = 0;
        for(int i = 0; i <= n; i++){
            if(isDivisible(i)) sum += i;
        }
        return sum;
    }
};