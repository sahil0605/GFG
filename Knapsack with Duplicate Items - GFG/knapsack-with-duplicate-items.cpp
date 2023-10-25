//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int N, int W, int val[], int wt[] ,int idx,vector<vector<int>>&dp){
        if(idx == N)return 0;
        if(dp[idx][W]!=-1)return dp[idx][W];
        int take = 0;
        if(W >= wt[idx]){
            take = val[idx] + helper(N,W-wt[idx],val,wt,idx,dp);
        }
        int  notTake =  helper(N,W,val,wt,idx+1,dp);
        return dp[idx][W]= max(take,notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return helper(N,W,val,wt,0,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends