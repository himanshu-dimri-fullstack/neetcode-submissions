class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapp;
        for(int i=0;i<nums.size();i++){
            int secondNum = target - nums[i];
            auto it = mapp.find(secondNum);
            if(it!=mapp.end()){
                return {it->second,i};
            }
            else{
                mapp.insert({nums[i],i});
            }
        }
        return {-1,-1};
    }
};
