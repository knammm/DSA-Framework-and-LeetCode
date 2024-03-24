class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = INT_MIN;
        int left = 0;
        int right = height.size() - 1;
        // When we decrease the width => must keep the higher height
        // because area ~ height and width
        while(left < right){
            int area = min(height[left], height[right]) * (right-left);
            result = max(result, area);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return result;
    }
};