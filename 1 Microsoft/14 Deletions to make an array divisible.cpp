class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        int gcx = b[0];
        
        for(int i = 1; i < b.size(); i++){
            gcx = __gcd(gcx, b[i]);
        }
        
        for(int i = 0; i < a.size(); i++){
            int last = a[i];
            if(gcx % last == 0){
                return i;
            }
            while(i+1 < a.size() && a[i+1] == last){
                i++;
            }
        }
        
        return -1;
       
    }
};