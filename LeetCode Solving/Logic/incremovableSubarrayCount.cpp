class Solution {
public:
    bool check(vector<int> v){
        if(v.size() == 0 || v.size() == 1) return 1;
        for(int i = 1; i < v.size(); i++){
            if(v[i] <= v[i - 1]) return 0;
        }
        return 1;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            vector<int> copy = nums;
            // Try each subarr, formula for each index is size - index
            for(int k = 0; k < nums.size() - i; k++){
                for(int j = i; j < copy.size() - 1; j++){
                    // Tele each element to the left
                    copy[j] = copy[j + 1];
                }
                copy.pop_back();
                // Check sorted
                if(check(copy)) count++;
            }
        }
        return count;
    }
};