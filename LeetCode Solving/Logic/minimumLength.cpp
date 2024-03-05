class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        if(s[0] != s[n - 1]) return n;
        deque<char> deq;
        for(int i = 0; i < n; i++){
            deq.push_back(s[i]);
        }
        
        deque<char>::iterator it1 = deq.begin();
        deque<char>::iterator it2 = deq.end() - 1;
        
        // cout << *it1 << " " << *(it1 + 2) << endl;
        while(*it1 == *it2 && it1 != deq.end() && it2 != deq.end() && deq.size() > 1){
            while(*it1 == *(it1 + 1) && deq.size() > 2){
                deq.pop_front();
                it1 = deq.begin();
            }
            while(*it2 == *(it2 - 1) && deq.size() > 2){
                deq.pop_back();
                it2 = deq.end() - 1;
            }
            // Set back
            deq.pop_front();
            deq.pop_back();
            it1 = deq.begin();
            it2 = deq.end() - 1;
        }
        return deq.size();
    }
};