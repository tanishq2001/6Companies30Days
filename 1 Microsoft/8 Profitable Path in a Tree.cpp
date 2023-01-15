class Solution {
public:

    pair<bool,int> dfs(int v,int k,vector<vector<int>> &adj,vector<bool> &vis,vector<int>& amount){
        vis[v]=1;
        if(v==0) return {1,0};
        for(auto i : adj[v]){
            if(!vis[i]){
                pair<bool,int>x = dfs(i,k+1,adj,vis,amount);
                if(x.first==1){
                    if(k==x.second+1){
                        amount[v]/=2;
                    }
                    else if(k<x.second+1){
                        amount[v]=0;
                    }
                    return {1,x.second+1};
                }
            }
        }
        return {0,0};
    }


    int dfsx(int v,vector<vector<int>> &adj,vector<bool> &vis,vector<int>& amount){
        vis[v]=1;
        int ans = INT_MIN;
        bool flag = 0;
        for(auto i : adj[v]){
            if(!vis[i]){
                flag = 1;
                ans=max(ans, dfsx(i,adj,vis,amount));
            }
        }
        if(flag) return ans+amount[v];
        return amount[v];
    }

    



    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>vis(n,0);
        dfs(bob,0,adj,vis,amount);
        vector<bool>visited(n,0);
        return dfsx(0,adj,visited,amount);
    }
};