class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        // Using map to find freq
        for(int i = 0; i < arr.size(); i++){
            map[arr[i]]++;
        }
        // Import freq into vector and sort
        vector<int> freq;
        for(auto& it:map){
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end());
        // Using subtraction until k == 0 or k < 0
        for(int i = 0; i < freq.size(); i++){
            k -= freq[i];
            if(k == 0){
                return freq.size() - (i + 1);
            }
            else if(k < 0){
                return freq.size() - i;
            }
        }
        return 0;
    }
};