class Solution {
public:
    int numberOfSubstrings(string s) {
        int last = 0;
        int ans = 0;
        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            if(mp.size() == 3){
                while(1){
                    if(mp[s[last]] > 1){
                        mp[s[last]]--;
                    }
                    else{
                        break;
                    }
                    last++;
                }
                ans += last+1;
            }
        }
        return ans;
    }
};