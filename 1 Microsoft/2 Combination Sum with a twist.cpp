class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> v;
    
    void dfs(int k,int sum){
        if(sum == 0 && k==0){
            ans.push_back(v);
            return;
        } 
        if(k == 0) return;
        if(sum < 0) return;
        int start = 1;
        if(v.size()){
            start = *v.rbegin()+1;
        }
        
        for(int i = start; i < 10; i++){
            v.push_back(i);
            dfs(k-1, sum - i);
            v.pop_back();
        
        }
    }
    
    
    
    
    vector<vector<int>> combinationSum3(int k, int n){
        dfs(k, n);
        return ans;
    }
};