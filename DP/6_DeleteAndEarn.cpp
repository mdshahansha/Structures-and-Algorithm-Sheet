class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        if(nums.size()==2){
            if((nums[0]-nums[1])==1)
                return nums[1];
                else{
                    return nums[0]+nums[1];
                }
        }
        map<int,int> freq;
        vector<int> arr;
        int dp[20001];
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;      
        }
      
        for (auto it = freq.begin(); it != freq.end(); ++it) {
        int num=it->first;
        arr.push_back(num);
        }

        int n = arr.size();
        if (n == 0) {
            return 0;
        }

          dp[0]=nums[0]*freq[nums[0]];
          if (n > 1) {
            dp[1] = max(dp[0], arr[1] * freq[arr[1]]);
        } else {
            return dp[0];
        }
        if(arr[1]-arr[0]==1)
        dp[1]=max(dp[0],arr[1]*freq[arr[1]]);
        else{
        dp[1]= (dp[0]+arr[1]*freq[arr[1]]);
        }
        
 cout<<dp[1]<<" -";
        for(int i=2;i<arr.size();i++){
            cout<<dp[i]<<" ";

            if( arr[i]==arr[i-1]+1 ){
            dp[i]=max(dp[i-1],arr[i]*freq[arr[i]]+dp[i-2] );
            }
            // else if(arr[i]+1==arr[i+1]){
            // dp[i]=max(arr[i+1]*freq[arr[i+1]],arr[i]*freq[arr[i]]);
            // }
            else{
            dp[i]= dp[i-1]+arr[i]*freq[arr[i]];
            }
            cout<<dp[i]<<" ";
        }

        return dp[n-1];
             

            
        
    }
};