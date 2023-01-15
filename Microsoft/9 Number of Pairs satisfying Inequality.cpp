class Solution {
public:
   
    long long t = 0;
    int d;
    
    void merge(vector<int>& a, int low, int mid, int high){
        vector<int> ans;
        int start1 = low;
        int start2 = mid+1;
        
        while(start1 < mid+1 && start2 < high+1){
            if(a[start1] - a[start2] <= d){
                t += (high - start2 + 1);
                start1++;
            }
            else{
                start2++;
                
            }
        }
        start1 = low;
        start2 = mid+1;
        while(start1 < mid+1 && start2 < high+1){
            if(a[start1] < a[start2]){
                ans.push_back(a[start1++]);
            }
            else{
                ans.push_back(a[start2++]);
            }
        }
        
        while(start2 < high+1){
            ans.push_back(a[start2++]);
        }
        
        while(start1 < mid+1){
            ans.push_back(a[start1++]);
        }
        int count = 0;
        for(int i = low; i< high+1;i++){
            a[i] = ans[count++];
        }
        
    }

    
    void mergesort(vector<int>& a, int low, int high){
        if(low >= high) return;
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high);
    }
    
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        for(int i=0;i<n;i++){
            nums1[i] = nums1[i]-nums2[i];
        }
        d = diff;
        mergesort(nums1, 0, n-1);
        return t;
    }
};