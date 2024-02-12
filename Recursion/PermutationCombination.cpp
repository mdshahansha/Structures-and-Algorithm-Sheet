
#include <vector>
#include <string>
using namespace std;
 
    void solve(vector<int>& nums,vector<vector<int>> &ans,int index)
    {
        if(nums.size()==index){
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++)
        {
            
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1);
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
            vector<int> sub;
         solve(nums,ans,0);

         return ans;
    }
    