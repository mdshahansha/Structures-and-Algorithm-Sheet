class Solution {
public:
    vector<int> countBits(int n) {
        
        //  vector<int> ans;
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // Use the fact that the count of set bits in i is equal to the count of set bits in i / 2
            // plus 1 if i is odd, or 0 if i is even.
            dp[i] = dp[i / 2] + (i % 2);
        }

        return dp;
        //  for(int i=0;i<=n;i++){
        //      int num=i;
        //      int count=0;
        //      while(num>0){
        //          count+= num&1;// for cheking it is even or odd (common  method)
        //          num = num>>1; //right shift kardiya ,
        //      }
        //     //   while (num > 0) {
        //     //     int rem = num % 2;
        //     //     num /= 2;
        //     //     if (rem == 1) {
        //     //         one++;
        //     //     }
        //     // }
        //      ans.push_back(count);
        //  }
        //  return ans;
    }
};