class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) { 
        return a.second < b.second; 
    } 
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        vector<pair<int, int>> vec;
        for (auto& it : map) { 
            vec.push_back({it.first, it.second}); 
        }
        sort(vec.begin(),vec.end());

        reverse(vec.begin(), vec.end());

        // Sort using comparator function 
        stable_sort(vec.begin(), vec.end(), cmp); 
        vector<int> result;
        
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec[i].second;j++)
            {
                result.push_back(vec[i].first);
            }
        }

        return result;
    }
};