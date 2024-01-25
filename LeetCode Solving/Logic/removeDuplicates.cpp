class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
        std::set<int> numSet = {};
        for(int i = 0; i < nums.size(); ++i){
            numSet.insert(nums[i]);
        }

        int i = 0;
        for(auto& element:numSet){
            nums[i] = element;
            i += 1;
        }

        int newSize = numSet.size();
        return newSize;
    }
};