class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<char> v1, v2;
        for(int i = 0; i < s.length(); i++){
            v1.push_back(s[i]);
            v2.push_back(t[i]);
        }
        v2.push_back(t[(int)t.length() - 1]);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for(int i = 0; i < s.length(); i++){
            if(v1[i] != v2[i]){
                return v2[i];
            }
        }
        return v2[(int)v2.size() - 1];
    }
};