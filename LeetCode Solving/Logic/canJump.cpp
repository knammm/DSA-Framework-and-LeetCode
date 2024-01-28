class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return true;
        }
        if(nums[0] == 0){
            return false;
        }

        int maxJump = 0;
		// Search for index => find max cell that can jump.
		// Case 1: traverse to the cell that greater than max jump => false
		// Case 2: having the maxJump > size - 1 => true
		// Update the maxJump every traverse.
        for(int i = 0; i < size - 1; i++){
            if(i > maxJump){
                return false;
            }

            if(nums[i] + i > maxJump){
                maxJump = nums[i] + i;
            }

            if(maxJump >= size - 1){
                return true;
            }
        }
        return false;
    }
};