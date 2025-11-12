class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxsum=0;
        
        for(int i=1;i+1<m;i++){
            for(int j=1;j+1<n;j++){
           int sum=grid[i][j]+grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1]+grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
           maxsum=max(maxsum,sum);
            }
        }
        return maxsum;
    }
};