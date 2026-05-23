class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int l=0, r=nums.size();
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid] < target)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }

    int upperBound(vector<int>& nums, int target){
        int l=0, r=nums.size();
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid] <= target)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lb = lowerBound(nums,target);
        if(lb==nums.size()||nums[lb]!=target) return {-1,-1};
        int ub = upperBound(nums,target)-1;

        return {lb, ub};
    }
};