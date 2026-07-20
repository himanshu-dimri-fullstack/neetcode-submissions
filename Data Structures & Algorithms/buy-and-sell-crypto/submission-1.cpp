class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int r = 1;
        int maxi = 0;
        while(r<n){
            int profit = prices[r]-prices[l];
            maxi = max(maxi,profit);
            while(profit<=0){
                if(l==r){
                    break;
                }
                l++;
                int profit = prices[r]-prices[l];
            }
           r++;
        }
        return maxi;
    }
};
