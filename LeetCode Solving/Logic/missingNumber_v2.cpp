class Solution {
public:
    int missingNumber(vector<int>& nums) {
		// Su dung cong thuc cong
        int n = nums.size();
        int sumAll = (n * (n + 1)) / 2;
        for(int i = 0; i < nums.size(); i++){
            sumAll -= nums[i];
        }
        return sumAll;
    }
};