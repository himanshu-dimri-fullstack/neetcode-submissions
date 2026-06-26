class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1]){
        //         return nums[i];
        //     }
        // }
        unordered_map<int,int> mapp;
        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]++;
        }
        for(auto it: mapp){
            if(it.second>1){
                return it.first;
            }
        }
        return -1;
    }
};
