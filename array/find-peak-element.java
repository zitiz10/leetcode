class Solution {
    public int findPeakElement(int[] nums) {
        int peakin=0;
        int n=nums.length;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                peakin=i+1;
            }
        }
        return peakin;
    }
}