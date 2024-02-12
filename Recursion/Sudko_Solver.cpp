#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    
   bool isSafe(int row, int col, vector<vector<char>>& board, char val) 
   {
       
       for (int i = 0; i < 9; i++) {
           // Row check
           if (board[row][i] == val) {
               return false;
           }
           // Column check
           if (board[i][col] == val) {
               return false;
           }
           // 3x3 Matrix check
           if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
               return false;
           }
       }
       return true;
   }



   bool solve(vector<vector<char>>& board) {
       int n = board.size();

       for (int row = 0; row < n; row++) {
           for (int col = 0; col < n; col++) {
               // Cell empty
               if (board[row][col] == '.') {
                   for (char val = '1'; val <= '9'; val++) 
                    { // which effectively means the loop will execute for values '1' through '9'.

                       if (isSafe(row, col, board, val)) {
                           board[row][col] = val; // Assign char directly
                           // Recursive call
                           if (solve(board)) {
                               return true;
                           } else {
                               // Backtrack
                               board[row][col] = '.'; // Reset to empty
                           }
                       }
                   }
                   return false; // If no valid value found
               }
           }
       }
       return true; // Solved Sudoku
   }


   void solveSudoku(vector<vector<char>>& board) {
       solve(board);
   }
};


