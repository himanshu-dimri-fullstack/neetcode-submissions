class Solution {
public:
bool checkFn(vector<int>& piles, int h, int mid){
int k = 0;
for(int i=0;i<piles.size();i++){
    k = k + ceil((double)piles[i]/mid);
}
if(k>h){
    return false;
}
return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(int i=0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        int low = 1;
        int high = maxi;

        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(checkFn(piles,h,mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
