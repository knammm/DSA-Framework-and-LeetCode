class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0;
        int j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        if(result.size() <= 1) return result;
        // Remove collapse elements
        vector<int>::iterator it;
        for(it = result.begin(); it != result.end() - 1; it++){
            if(*it == *(it + 1)) {
                result.erase(it);
                it--;
            }
        }
        return result;
    }
};