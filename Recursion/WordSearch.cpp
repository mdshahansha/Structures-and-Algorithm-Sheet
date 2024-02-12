class Solution {
public:
bool help(int i,int j,vector<vector<char>>& board,string word,int row,int col,int len){
    
    if(word.size()==len){
        return true;
    }
    if(i<0 || j<0 || i==row || j==col || board[i][j]!=word[len]) return false;
    
    char temp=board[i][j]; 
    board[i][j]='#';

    bool op1=help(i+1,j,board,word,row,col,1+len);
    bool op2=help(i-1,j,board,word,row,col,1+len);
    bool op3=help(i,j-1,board,word,row,col,1+len);
    bool op4=help(i,j+1,board,word,row,col,1+len);


    board[i][j]=temp;
    return op1 || op2 || op3 || op4;


}
    bool exist(vector<vector<char>>& board, string word) {

        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(help(i,j,board,word,n,m,0)) return true ; 
            }
        }
        return false;
        
    }
};