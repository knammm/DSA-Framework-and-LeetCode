class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Using dictionary
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < strs.size(); i++){
            // Sort the word to get the key value
            string key = strs[i];
            sort(key.begin(), key.end());

            // Find in the dictionary
            if(map.find(key) == map.end()){
                map[key] = {strs[i]}; // vector
            }
            else{
                map[key].push_back(strs[i]);
            }
        }
        // Convert map to vector
        vector<vector<string>> result;
        for(auto& it:map){
            result.push_back(it.second);
        }
        return result;
    }
};