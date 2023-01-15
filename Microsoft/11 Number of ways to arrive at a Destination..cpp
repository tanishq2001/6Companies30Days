
typedef pair<long long, long long> pi;
class Solution {    
public:
    
    int countPaths(int n, vector<vector<int>>& edges) {
        vector<pi>adj[n+1];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        vector<long long>edgewight(n, LONG_MAX);
        vector<long long>ans(n, 0);
        edgewight[0] = 0;
        ans[0] = 1;
        
        pq.push({0,0});
        while(!pq.empty()){
            pi x=pq.top();
            pq.pop();
            long long a=x.second;
            long long b=x.first;
            if(edgewight[a]<b) continue;
            for(auto i : adj[a]){
                if( edgewight[i.first] >  b+i.second ){
                    edgewight[i.first] = b+i.second;
                    ans[i.first] = ans[a] ;
                    pq.push({edgewight[i.first],i.first});
                }
                else if( edgewight[i.first] ==  b+i.second ){
                    ans[i.first] = ((long long)ans[i.first] + (long long)ans[a]) % 1000000007;
                } 
            }
        }
        return ans[n-1];
    }
};