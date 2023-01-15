class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return 0;
        stack<int>s;
        int start = n-1, end = 0;
        
        for(int i = 0; i < n; i++){
            while(s.size() && nums[s.top()] > nums[i]){
                start = min(start, s.top());
                s.pop();
            }
            s.push(i);
        }
        
        while(s.size()) s.pop();
        
        for(int i = n-1; i >= 0; i--){
            while(s.size() && nums[s.top()] < nums[i]){
                end = max(end, s.top());
                s.pop();
            }
            s.push(i);
        }
        
        if(start >= end) return 0;
        
        
        return end - start + 1;
    }
};