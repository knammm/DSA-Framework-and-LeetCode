class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> combine(size);
        int pos = 0, neg = 1;
        for(int i = 0; i < size; i++){
            if(nums[i] >= 0){
                combine[pos] = nums[i];
                pos += 2;
            }
            else{
                combine[neg] = nums[i];
                neg += 2;
            }
        }
        return combine;
    }
};