class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        int max = INT_MIN;
        int ans = 0;
        for(auto& it: map){
            if(max < it.second){
                max = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};