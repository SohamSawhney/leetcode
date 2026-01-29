// class Solution {
// public:
// int f(vector<vector<int>>&matrix,int i,int j, vector<vector<int>>&dp){
   
//     if(j<0 || j>=matrix[0].size()){
//         return 1e8;
//     }
//          if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     if(i==0){
//         return dp[i][j]=matrix[i][j];   // i==0
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

          vector<vector<int>>dp(n,vector<int>(m,-1));
          for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
          }
          for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
               
              int u  = matrix[i][j] + dp[i-1][j];

int ld = 1e8;
if (j-1 >= 0) {
    ld = matrix[i][j] + dp[i-1][j-1];
}

int rd = 1e8;
if (j+1 < m) {
    rd = matrix[i][j] + dp[i-1][j+1];
}

dp[i][j] = min(u, min(ld, rd));


            }
          }
          int mini=dp[n-1][0];
          for(int j=1;j<m;j++){
            mini=min(mini,dp[n-1][j]);
          }

          return mini;

      
    }
};
