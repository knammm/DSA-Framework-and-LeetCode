class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        // Sorted => compare the last vs the first
        sort(strs.begin(), strs.end());
        string firstStr = strs[0];
        string lastStr = strs[strs.size() - 1];
        int minLength = min(firstStr.length(), lastStr.length());
        for(int i = 0; i < minLength; i++){
            if(firstStr[i] == lastStr[i]){
                ans += firstStr[i];
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};