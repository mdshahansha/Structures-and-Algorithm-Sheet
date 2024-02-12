#include <iostream>
#include <vector>
using namespace std;


//COMBINATION I
class Solution {
public:

void solve(vector<int>& candidates,vector<vector<int>> &ans,vector<int> &aux,int target,int index){

    if(index==candidates.size()){
        if(target==0)
        ans.push_back(aux);
        return;
    }

    if(candidates[index]<=target){
        aux.push_back(candidates[index]);
        solve(candidates,ans,aux,target-candidates[index],index);   //index+1 ; -> we dont increase the index because we want to repeat the elements
        aux.pop_back();
    }
        solve(candidates,ans,aux,target,index+1);

}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> aux;
        solve(candidates,ans,aux,target,0);
        return ans;
    }
};



//COMBINATION II
class Solution {
public:
void solve(vector<int>& candidates,vector<vector<int>> &ans,vector<int> &aux,int target,int index){

    if(index==candidates.size()){
        if(target==0)
        ans.push_back(aux);
        return;
    }

    // if()
    if(candidates[index]<=target){
        aux.push_back(candidates[index]);
        solve(candidates,ans,aux,target-candidates[index],index+1);   //index+1 ; -> we dont increase the index because we want to repeat the elements
        aux.pop_back();

    }
     while(index+1<candidates.size() && candidates[index]==candidates[index+1]) index++;
        solve(candidates,ans,aux,target,index+1);


}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        vector<int> aux;
        sort(candidates.begin(),candidates.end());
        solve(candidates,ans,aux,target,0);
        return ans;
    }
};


//COMBINATION III
class Solution {
public:
void solve(int k,vector<vector<int>> &ans,vector<int> &aux,int target,int index){

    if(k==0)
    {
        if(target==0)
        ans.push_back(aux);
        return;
    }


        if(index==10)
            return;

    
    if(index<=target){
        aux.push_back(index);
        solve(k-1,ans,aux,target-index,index+1);  
        aux.pop_back();
    } 
        
        solve(k,ans,aux,target,index+1);// ye include hie nhi hoga toh k ko decrement nhi karna h 


}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> aux;
        solve(k,ans,aux,n,1);
        return ans;
    }
};
