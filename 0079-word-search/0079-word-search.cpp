class Solution {
public:
   bool dfs(vector<vector<char>>& board, string word,int i,int j,int ind){
    if(ind==word.size()){
        return true;
    }
    if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!=word[ind]){
        return false;
    }

    char temp=board[i][j];
    board[i][j]='#';
   


        bool found = dfs(board, word, i + 1, j, ind + 1) ||
                     dfs(board, word, i - 1, j, ind + 1) ||
                     dfs(board, word, i, j + 1, ind + 1) ||
                     dfs(board, word, i, j - 1, ind + 1);

        // Restore the character (backtracking)
        board[i][j] = temp;

        return found;
   }
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int col=board[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};