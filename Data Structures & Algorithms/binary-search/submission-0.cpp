class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;

        while(hi>=lo){
            int mid = (hi+lo)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]>target) hi--;
            else lo++;
        }

        return -1;
    }
};
