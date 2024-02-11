class Solution {
public:
    // Compare function must be static
    static bool compareByLength(string a, const string b) {
        return a.length() > b.length();
    }
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.length(); i++){
            map[s[i]]++;
        }
        // Convert to vector and sort
        vector<string> vec;
        for(auto& it:map){
            int count = it.second;
            string word = "";
            for(int i = 0; i < count; i++){
                word += it.first;
            }
            vec.push_back(word);
        }
        // Sort
        // default uses QuickSort. Can use Bubble sort for easy.
        sort(vec.begin(), vec.end(), compareByLength);

        string result = "";
        for(int i = 0; i < vec.size(); i++){
            result += vec[i];
        }
        return result;
    }
};