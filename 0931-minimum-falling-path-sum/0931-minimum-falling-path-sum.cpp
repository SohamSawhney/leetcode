// class Solution {
// public:
// int f(vector<vector<int>>&matrix,int i,int j, vector<vector<int>>&dp){
//     if(j<0 || j>=matrix[0].size()){
//         return 1e8;
//     }
//     if(i==0){
//         return dp[i][j]=matrix[i][j];   // i==0
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     int u=matrix[i][j]+f(matrix,i-1,j,dp);
//     int ld=matrix[i][j]+f(matrix,i-1,j-1,dp);
//     int rd=matrix[i][j]+f(matrix,i-1,j+1,dp);

//     return dp[i][j]=min(u,min(ld,rd));

// }
//     int minFallingPathSum(vector<vector<int>>& matrix) {

//         int n=matrix.size();
//         int m=matrix[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         int mini=1e8;

//         for(int j=0;j<m;j++){
//             mini=min(mini,f(matrix,n-1,j,dp));
           

            
//         }
//         return mini;
        
//     }
// };


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp = matrix; // copy first row

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = dp[i-1][j];
                int ld = (j > 0) ? dp[i-1][j-1] : 1e8;
                int rd = (j < m-1) ? dp[i-1][j+1] : 1e8;

                dp[i][j] += min(up, min(ld, rd));
            }
        }

        int ans = 1e8;
        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};
