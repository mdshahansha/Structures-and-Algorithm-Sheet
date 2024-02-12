#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidRow(vector<vector<char>> &grid,int curr_row,int n){

        for(int i=0;i<n;i++){
            if(grid[curr_row][i]=='Q')
            return false;
        }
        return true;
    }

    bool isValidCol(vector<vector<char>> &grid,int curr_col,int n){

        for(int i=0;i<n;i++){
            if(grid[i][curr_col]=='Q')
            return false;
        }
        return true;
    }
    bool isValidDiagonal(vector<vector<char>> &grid, int curr_row, int curr_col, int n) {
    int i = curr_row;
    int j = curr_col;

    // Check upper left diagonal
    while (i >= 0 && j >= 0) {
        if (grid[i][j] == 'Q') {
            return false;
        }
        i--;
        j--;
    }

    i = curr_row;
    j = curr_col;
    // Check upper right diagonal
    while (i >= 0 && j < n) {
        if (grid[i][j] == 'Q') {
            return false;
        }
        i--;
        j++;
    }

    i = curr_row;
    j = curr_col;
    // Check lower left diagonal
    while (i < n && j >= 0) {
        if (grid[i][j] == 'Q') {
            return false;
        }
        i++;
        j--;
    }

    i = curr_row;
    j = curr_col;
    // Check lower right diagonal
    while (i < n && j < n) {
        if (grid[i][j] == 'Q') {
            return false;
        }
        i++;
        j++;
    }

    return true;
}


    

        bool isValid(vector<vector<char>> &grid,int curr_row,int curr_col,int n){
            return ( isValidRow(grid,curr_row,n) && isValidCol(grid,curr_col,n) && isValidDiagonal(grid,curr_row,curr_col,n) );
        }


       vector<string> populate(vector<vector<char>> &grid,int n){
            vector<string> result;

            for(int i=0;i<n;i++){
                string temp=""; 
                for(int j=0;j<n;j++){
                    temp+=grid[i][j];
                }
                result.push_back(temp);
            }
        return result;     
       }

void solve(vector<vector<char>> &grid,vector<vector<string>> &ans,int curr_row,int n){
    if(curr_row==n){
        vector<string> result=populate(grid,n);
        ans.push_back(result);
        return;
    }

    for(int i=0;i<n;i++){
        // bool isValid(vector<vector<char>> &grid,int curr_row,int curr_col,n)
        if(isValid(grid,curr_row,i,n))
        {
            grid[curr_row][i]='Q';
            solve(grid,ans,curr_row+1,n);
            grid[curr_row][i]='.';
        }

    }

}
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ans;
         vector<vector<char>> grid(n,vector<char>(n,'.'));//complteely assign '.' in 2D vector
    solve(grid,ans,0,n);

        return ans;
    }
};