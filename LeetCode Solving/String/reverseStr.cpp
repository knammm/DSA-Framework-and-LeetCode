class Solution {
public:
    string reverse(string s){
        stack<char> st;
        string res = "";
        for(int i = 0; i < s.length(); i++){
            st.push(s[i]);
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
    
    string reverseStr(string s, int k) {
        if(s.length() < k){
            return reverse(s);
        }
        string result = "";
        for(int i = 0; i < s.length(); i++){
            if(i % (2 * k) == 0){
                string rev_str = s.substr(i, k);
                result += reverse(rev_str);
                i += k - 1;
            }
            else{
                result += s[i];
            }
        }
        return result;
    }
};