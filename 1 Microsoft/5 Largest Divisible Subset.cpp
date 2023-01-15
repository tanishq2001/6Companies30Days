class Solution {
public:
    

       
    
    vector<int> largestDivisibleSubset(vector<int>& a){
        sort(a.begin(),a.end());
        int dp[1000];
        int pre[1000];
        int max=0,index=1;
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            dp[i]=1;
            pre[i]=-1;
            for(int j=i-1;j>=0;j--){
                if(a[i]%a[j]==0){
                    if(dp[j] + 1 >  dp[i]){
                        dp[i]=dp[j] + 1;
                        pre[i]=j;
                    }
                }
            }
            if(dp[i]>max){
                max=dp[i];
                index=i;
            }
        }
        
        while(index!=-1){
            ans.push_back(a[index]);
            index=pre[index];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};