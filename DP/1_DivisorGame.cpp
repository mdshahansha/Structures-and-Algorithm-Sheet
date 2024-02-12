// #include<bits/stdc++.h>
class Solution
{
public:
    int dp[1001];
    int help(int n)
    {
        if (n == 1)
            return 0;

        // base case
        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                if ((help(n - i) == 0))
                    return dp[n] = 1;
                // if next player looses the game ,then we win
            }
        }
        return dp[n] = 0;
    }
    // int help(int n)
    // {
    //     if(n==1)
    //     return 0;

    //     for(int i=1;i<n;i++)
    //     {
    //         if(n%i==0)
    //         {
    //               if((help(n-i)==0)) return 1;
    //             //if next player looses the game ,then we win
    //         }
    //     }
    //     return 0;
    // }

    bool divisorGame(int n)
    {
        memset(dp, -1, sizeof dp);
        return help(n);
    }
};