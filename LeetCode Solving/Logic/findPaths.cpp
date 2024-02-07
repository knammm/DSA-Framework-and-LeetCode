class Solution {
public:
    void recursive(int m, int n, int maxMove, int startRow, int startColumn, int& ans){
        if(startColumn < 0 || startColumn >= n || startRow < 0 || startRow >= m){
            // Stop condition
            ans++;
            return;
        }
        // Move 4 ways
        if(maxMove > 0) recursive(m, n, maxMove - 1, startRow - 1, startColumn, ans); // up
        if(maxMove > 0) recursive(m, n, maxMove - 1, startRow + 1, startColumn, ans); // down
        if(maxMove > 0) recursive(m, n, maxMove - 1, startRow, startColumn - 1, ans); // left
        if(maxMove > 0) recursive(m, n, maxMove - 1, startRow, startColumn + 1, ans); // right
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        recursive(m, n, maxMove, startRow, startColumn, ans);
        return ans;
    }
};