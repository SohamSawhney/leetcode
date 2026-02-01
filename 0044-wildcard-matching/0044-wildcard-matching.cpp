class Solution {
public:
bool f(const string& s,const string& p,int m,int n,int i,int j,vector<vector<int>>&dp){


   if(dp[i][j]!=-1){
    return dp[i][j];
   }
    //base case 
    if(i==m and j==n){
        return true;
    }
    if(i!=m and j==n){
        return false;
    }
    if(i==m and j!=n){
        bool flag=true;
        for(int k=j;k<n;k++){
            if(p[k]!='*'){
               flag=false;
               break;
            }
        }
        return dp[i][j]=flag;
        
    }



    // recursive case
    // f()



    if(s[i]==p[j] or p[j]=='?'){
       return f(s,p,m,n,i+1,j+1,dp);

    }
    else  if(p[j]=='*'){
        return f(s,p,m,n,i,j+1,dp) or f(s,p,m,n,i+1,j,dp);

    }
    else{
        return false;
    }

}
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
                vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return f(s,p,m,n,0,0,dp);
        
    }
};