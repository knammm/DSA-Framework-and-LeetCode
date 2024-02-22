class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // New vector with size n + 1 (mang danh dau)
        vector<int> in(n + 1);
        vector<int> out(n + 1);
        for(int i = 0; i < trust.size(); i++){
            in[trust[i][1]]++;
            out[trust[i][0]]++; // out != 0 means the person cannot be a judge
        }
        for(int i = 1; i < n + 1; i++){
            // true when n - 1 people trust and the person trust nobody !
            if(in[i] == n - 1 && out[i] == 0) return i;
        }
        return -1;
    }
};