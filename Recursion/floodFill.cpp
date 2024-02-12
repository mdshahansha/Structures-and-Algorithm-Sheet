#include <vector>
#include <string>
using namespace std;

class Solution {
public:

void solve(vector<vector<int>>& image,int i,int j,int n,int m,int oldColor,int newColor){
   //you are making recursive calls without checking if the neighboring pixels have already been visited or if they are within the bounds of the image. 
    if(i<0 || j<0 || n==i || m==j || image[i][j]!=oldColor || image[i][j] == newColor){//image[i][j]!=oldColor, mtlb there is different collor already
return ;
    }

    image[i][j]=newColor;
    
        solve(image,i+1,j,n,m,oldColor,newColor);
        solve(image,i-1,j,n,m,oldColor,newColor);
        solve(image,i,j-1,n,m,oldColor,newColor);
        solve(image,i,j+1,n,m,oldColor,newColor);

}
   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int oldColor=image[sr][sc];
       int n=image.size();
       int m=image[0].size();
        solve(image,sr,sc,n,m,oldColor,color);
       
       return image;
       

    }
};