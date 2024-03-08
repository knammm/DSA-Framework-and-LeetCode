class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int max = INT_MIN;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
            if(max < map[nums[i]]){
                max = map[nums[i]];
            }
        }
        int count = 0;
        for(auto& it:map){
            if(it.second == max){
                count += max;
            }
        }
        return count;
    }
};