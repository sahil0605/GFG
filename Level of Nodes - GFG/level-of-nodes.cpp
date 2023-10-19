//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    queue<pair<int,int>>q;
	    vector<int>vis(V,0);
	    q.push({0,0});
	    vis[0]=1;
	    while(!q.empty()){
	        int n = q.size();
	        for(int i=0;i<n;i++){
	            int front = q.front().first;
	            int level = q.front().second;
	            q.pop();
	            if(front == X)return level;
	            for(int j=0;j<adj[front].size();j++){
	                if(!vis[adj[front][j]]){
	                    q.push({adj[front][j],level+1});
	                    vis[adj[front][j]]=1;
	                }
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends