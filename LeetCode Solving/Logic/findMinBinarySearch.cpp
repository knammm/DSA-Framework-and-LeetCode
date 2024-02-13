class Solution {
public:
    int findMin(vector<int>& nums) {
        // Binary Search
        int low = 0;
        int high = nums.size() - 1;
        int result = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[low] <= nums[mid]){
                result = min(result, nums[low]);
                low = mid + 1;
            }
            else{
                result = min(result, nums[mid]);
                high = mid - 1;
            }
        }
        return result;
    }
};