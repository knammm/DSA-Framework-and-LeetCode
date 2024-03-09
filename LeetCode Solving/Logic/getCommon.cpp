class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int find = -1;
        int i = 0; 
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                find = nums1[i];
                break;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return find;
    }
};