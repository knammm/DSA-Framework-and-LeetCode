class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        set<string> mySet;
        for(int i = 0; i <= s.size() - k; i++){
            mySet.insert(s.substr(i, k));
        }
        long long maxSize = 1;
        while(k > 0){
            maxSize *= 2;
            k--;
        }
        return (mySet.size() == maxSize);
    }
};