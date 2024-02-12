#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool compare(string& currString,vector<int>& freq){

        vector<int> selfCheck(26,0);
        for(int i=0;i<currString.size();i++){
            if(selfCheck[currString[i]-'a']==1) return false;
            
            selfCheck[currString[i]-'a']=1;
        }

// loop for comparing currString with already selected characters that are present in the vector<int> freq
        for(int i=0;i<currString.size();i++){
            if(freq[currString[i]-'a']==1) return false;
        }

        return true;
    }
int help(int i,vector<string>& arr,vector<int>& freq,int len)
{
    if(i==arr.size())
    return len;

    string currString=arr[i];

    if(compare(currString,freq)==false){
        return help(i+1,arr,freq,len);


    // else there are no overlap of characters as well as all the characters are unique
    // hence we have two options one to pick the currString or to skip it & then compare both to get the best answer out of it
    }else{

        for (int j = 0; j < currString.size(); j++)
            {
            // mark the indices as 1 so that in future we know that what all characters we have selected
            freq[currString[j] - 'a'] = 1;
            }

           len += currString.size();
           //pick
           int op1=help(i+1,arr,freq,len);

                //unpick
            for (int j = 0; j < currString.size(); j++)
            {
            freq[currString[j] - 'a'] = 0;
            }

           len -= currString.size();
           //unpick call
           int op2=help(i+1,arr,freq,len);
return max(op1,op2);

    }

} 

    int maxLength(vector<string>& arr) {
            vector<int> freq(26,0);
            return help(0,arr,freq,0);
    }
};