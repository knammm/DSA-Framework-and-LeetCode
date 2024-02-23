class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // using XOR because the element are unique
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result ^= nums[i];
            result ^= i;
        }
        result ^= nums.size();
        return result;
    }
};