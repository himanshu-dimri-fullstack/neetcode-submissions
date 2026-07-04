class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,int> mapp;
        for(int i=0;i<s.size();i++){
            mapp[s[i]]++;
            mapp[t[i]]--;
        }
        for(auto it: mapp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};
