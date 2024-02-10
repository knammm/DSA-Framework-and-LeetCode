class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        int num = 0;
        for(int i = 1; i < 10; i++){
            num = i;
            for(int j = num + 1; j < 10; j++){
                num = num * 10 + j;
                if(num >= low && num <= high){
                    v.push_back(num);
                }
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};