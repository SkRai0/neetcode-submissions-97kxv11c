class Solution {
    //TC: O(N^2)
    int getMax(vector<int>& nums, int l, int r){
        int maxi = INT_MIN;
        for(int i=l;i<=r;i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int l = 0, r = k-1;
        while(r<nums.size()){
            int maxi = getMax(nums, l, r);
            ans.push_back(maxi);
            l++, r++;
        }

        return ans;
    }
};
