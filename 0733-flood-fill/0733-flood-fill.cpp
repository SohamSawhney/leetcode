class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>&ans,int delrow[],int delcol[],int newcolor,int inicolor){
     ans[row][col]=newcolor;

     int n=image.size();
     int m=image[0].size();
     for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicolor && ans[nrow][ncol]!=newcolor ){
    dfs(nrow,ncol, image,ans,delrow,delcol,newcolor,inicolor);
        }
     }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialcolor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delrow[4]={-1,0,+1,0};
        int delcol[4]={0,+1,0,-1};
        dfs(sr,sc,image,ans,delrow,delcol,color,initialcolor);
        return ans;
    }
};