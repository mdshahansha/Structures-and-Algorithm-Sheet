class Solution {
public: 
 
//  1. RECUSRION 
 class Solution {
public:
    void solve(string s, vector<string> &output) {
        if (s.length() == 0) {
            output.push_back("");
            return;
        }

        vector<string> ans1;
        vector<string> ans2;

        int integer = s[0] - '0';
        char ch1 = 'a' + integer - 1;

        if(integer>0)
        solve(s.substr(1), ans1);

        int k = 0;
        if (s.length() > 1) {
            int doubleDigit = (integer * 10 + s[1] - '0');
            char ch2 = 'a' + doubleDigit - 1;
            // if(ch2[0]=='0'){
            //     continue;
            // }
            if (integer>0 && doubleDigit >= 10 && doubleDigit <= 26) {
                solve(s.substr(2), ans2);
            }

            for (int i = 0; i < ans1.size(); i++) {
                string sub = ch1 + ans1[i];
                output.push_back(sub);
            }
            for (int j = 0; j < ans2.size(); j++) {
                string sub = ch2 + ans2[j];
                output.push_back(sub);
            }
        } else {
            // Only single digit is left
            for (int i = 0; i < ans1.size(); i++) {
                string sub = ch1 + ans1[i];
                output.push_back(sub);
            }
        }
    }

    int numDecodings(string s) {
        if((s.length()==2 && s[0]=='0') || (s.length()==1 && s[0]=='0')  )
        return 0;
        vector<string> ans;

        solve(s, ans);
        return ans.size();
    }
}; 
    

     



//Recursion
class Solution {
public:
int solve(string s,int i){
    if(i>=s.size())
    return 1;

int ans=0;
    int op1=s[i]-'0',op2=0;
    
    if(i<s.size()-1){
        op2=op1*10 + s[i+1]-'0';
    }

    if(op1>0) ans+=solve(s,i+1);
    if(op1 && op2>0 && op2<=26) ans+=solve(s,i+2);

return ans;

}
   
};

//DP

    
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];//is not '0', it means we can consider it as a single-digit number (e.g., 1 to 9). 
                // In this case, dp[i] is updated by adding the value of dp[i - 1],
            }
            int doubleDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (doubleDigit >= 10 && doubleDigit <= 26) {
                dp[i] += dp[i - 2];// dp[i] is updated by adding the value of dp[i - 2],
                //  representing the number of ways to decode the substring ending two characters ago.
                //dp[i] ki value ko update kiya jata hai, dp[i - 2] ke value ko add kar ke, jo do characters
                // pehle tak ke substring ko decode karne ke tareeqon ko represent karta hai
            }
        }

        return dp[n];
    }
};