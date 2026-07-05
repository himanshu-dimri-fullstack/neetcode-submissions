class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mapp;
        for(int i=0;i<strs.size();i++){
            string s1 = strs[i];
            sort(s1.begin(),s1.end());
            mapp[s1].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it: mapp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
