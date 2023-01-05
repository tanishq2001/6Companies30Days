class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp;
        int a = 0, b = 0;
        for(int i = 0;i<secret.size();i++){
            if(secret[i] == guess[i]){
                a++;
            }
            else{
                mp[secret[i]]++;
            }
        }
        for(int i = 0;i<secret.size();i++){
            if(secret[i] != guess[i]){
                if(mp.find(guess[i]) != mp.end()){
                    if(mp[guess[i]] == 1){
                        mp.erase(guess[i]);
                    }
                    else{
                        mp[guess[i]]--;
                    }
                    b++;
                }
            }
        }
        string ans ="";
        ans += to_string(a);
        ans += 'A';
        ans += to_string(b);
        ans += 'B';
        return ans;
    }
};