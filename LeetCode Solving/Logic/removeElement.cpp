class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) {
            return 0;
        }
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == val){
                for(int j = i; j < nums.size() - 1; j++){
                    nums[j] = nums[j + 1];
                }
                nums.pop_back();
                i--;
            }
        }
        if(nums[nums.size() - 1] == val){
            nums.pop_back();
        }
        int returnVal = nums.size();
        return returnVal;
    }
};