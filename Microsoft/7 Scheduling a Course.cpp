class Solution {
public:
    unordered_map<int,bool> visited;
    unordered_map<int,bool> recstack;
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int>adj[]){
	    for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfsOf(i,adj)){
                   return 1;
                }
            }
        }
        return 0;
    }
    bool dfsOf(int V,vector<int> adj[]){
        if(visited[V]==0){
        	visited[V]=1;
            recstack[V] = 1;
        //	cout << V << " ";
        	for(int i=0;i<adj[V].size();i++){
        	  	if(!visited[adj[V][i]]){
    		        if(dfsOf(adj[V][i],adj)){
    		    		return 1;
    	    	    }
    	    	}
    	    	else if(recstack[adj[V][i]])  {
    	    	    return 1;
    	    	}   	    		
        	}
        }
        recstack[V] = 0;
    	return 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i< prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        if(isCyclic(numCourses,adj)){
             return 0;
        }
        return 1;
    }
};