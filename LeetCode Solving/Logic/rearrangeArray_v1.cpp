class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg, combine;
        // Separate pos, neg
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        int idx1 = 0, idx2 = 0;
        // Interleave
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                // positive goes first
                combine.push_back(pos[idx1++]);
            }
            else{
                combine.push_back(neg[idx2++]);
            }
        }
        return combine;
    }
};