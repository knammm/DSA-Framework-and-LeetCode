class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> map;
        int maxFreq = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
            maxFreq = max(maxFreq, map[nums[i]]);
        }
        int count = 0;
        for(auto& it:map){
            if(it.second == maxFreq){
                count += maxFreq;
            }
        }
        return count;
    }
};