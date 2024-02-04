class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        int count = 0;
        for(auto& it:map){
            if(it.second == 1){
                return -1;
            }
            // If freq % 3 == 0 => using operation 2.
            count += it.second / 3;
            // Check if freq % 3 != 0 => using opreation 1.
            if(it.second % 3 != 0){
                count++;
            }
        }
        return count;
    }
};