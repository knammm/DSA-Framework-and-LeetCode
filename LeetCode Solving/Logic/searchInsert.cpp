class Solution {
public:
    int binarySearch(vector<int> &nums, int target, int left, int right){
       int midVal = left + (right - left)/2;
        if(right < left){
            return right;
        }
        if(target < nums[midVal]){
            return binarySearch(nums, target, left, midVal - 1);
        }
        else if(target > nums[midVal]){
            return binarySearch(nums, target, midVal + 1, right);
        }
        else{
            return midVal;
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        if(target > nums[nums.size() - 1]){
            return nums.size();
        }
        else if(target < nums[0]){
            return 0;
        }
        int returnIndex = binarySearch(nums, target, 0, nums.size() - 1);
        if(nums[returnIndex] == target){
            return returnIndex;
        }
        else{
            return returnIndex + 1;
        }
    }
};