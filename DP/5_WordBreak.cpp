class Solution {
public:

//Reursion
 
bool solve(int i,string s,set<string>& st){
    if(i==s.size())
    return true;

    if(dp[i]!=-1)
    return dp[i];
    string temp;
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(st.find(temp)!=st.end()){//that this word is available in that set
            if(solve(j+1,s,st)) return dp[i]=1;
            }
        }
    return dp[i]=0;
}

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp,-1,sizeof dp);
        for(auto a: wordDict){
        st.insert(a);
        }
        return solve(0,s,st);
    }
 

//MEMO
bool solve(int i,string s,set<string>& st){
    if(i==s.size())
    return true;

    if(dp[i]!=-1)
    return dp[i];

string temp;
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(st.find(temp)!=st.end()){//that this word is available in that set
            if(solve(j+1,s,st)) return dp[i]=1;
            }
        }
return dp[i]=0;
}

// ..BOTTOM
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1; // Base case: empty string is always breakable

        for (auto a : wordDict) {
            st.insert(a);
        }

        for (int i = n - 1; i >= 0; i--) {
            string temp;
            for (int j = i; j < n; j++) {
                temp += s[j];
                if (st.find(temp) != st.end() && dp[j + 1]) {
                    dp[i] = 1;
                }
            }
        }

        return dp[0];
    }
};
