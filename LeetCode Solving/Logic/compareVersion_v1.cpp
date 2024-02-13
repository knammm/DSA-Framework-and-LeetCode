class Solution {
public:
    int compareVersion(string version1, string version2) {
        int lenV1 = version1.length();
        int lenV2 = version2.length();
        int i = 0;
        int j = 0;
        vector<int> v1;
        vector<int> v2;
        while(i < lenV1 || j < lenV2){
            int numVer = 0;
            while(i < lenV1 && version1[i] != '.'){
                numVer = numVer * 10 + (version1[i] - '0');
                i++;
            }
            i++;
            v1.push_back(numVer);
            numVer = 0;
            while(j < lenV2 && version2[j] != '.'){
                numVer = numVer * 10 + (version2[j] - '0');
                j++;
            }
            j++;
            v2.push_back(numVer);
        }
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] > v2[i]) return 1;
            else if(v1[i] < v2[i]) return -1;
        }
        return 0;
    }
};