class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <= 1){
            return;
        }
        int numZero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                nums.erase(nums.begin() + i);
                i--;
                numZero++;
            }
        }
        for(int i = 0; i < numZero; i++){
            nums.push_back(0);
        }
    }
};