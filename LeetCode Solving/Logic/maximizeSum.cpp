class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        if(k <= 0) return 0;
        int max = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(max < nums[i]){
                max = nums[i];
            }
        }
        int sum = max;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == max){
                nums.erase(nums.begin() + i);
                nums.push_back(max + 1);
                k--;
                break;
            }
        }
        int j = 1;
        while(k > 0){
            sum += max + j;
            nums.pop_back();
            j++;
            nums.push_back(max + j);
            k--;
        }
        return sum;
    }
};