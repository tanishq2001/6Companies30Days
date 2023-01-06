class Solution {
public:
    
    int maxRotateFunction(vector<int>& a) {
        int n=a.size(),ans,sum=0,sumx=0,i;
        for(i=0;i<n;i++){
            sumx+=a[i];
            sum+=i*a[i];
        }    
        ans=sum;
        for(i=n-1;i>0;i--){
            sum+=sumx-a[i]*n;
            ans=max(sum,ans); 
        }
        return ans;
    }
};