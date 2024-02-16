class Solution {
public:
    int findMin(unordered_map<int, int> mp){
        if(mp.size() == 0) return -1;
        int min = INT_MAX;
        for(auto& it:mp){
            if(it.second < min && it.second != 0){
                min = it.second;
            }
        }
        return min;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        for(int i = 0; i < arr.size(); i++){
            map[arr[i]]++;
        }
        set<int> s;
		// Find min => use set
        while(k != 0){
            int min = findMin(map);
            if(min != -1){
                for(auto it = map.begin(); it != map.end(); it++){
                    if(it->second == min){
                        it->second = it->second - 1;
                        if(it->second == 0) s.insert(it->first);
                        break;
                    }
                }
                k--;
            }
            else{
                return 0;
            }
        }
        return map.size() - s.size();
    }
};