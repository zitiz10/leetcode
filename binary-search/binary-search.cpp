class Solution {
private:
int binary_search(vector<int>& nums,int target,int l,int r){
    if(l>r) return -1;
    int mid=l+(r-l)/2;
    if(nums[mid]==target) return mid;
    else if(nums[mid]<target) 
     return binary_search(nums,target,mid+1,r);
    else 
     return binary_search(nums,target,l,mid-1);
}
public:
    int search(vector<int>& nums, int target) {
        int left =0;
        int right= nums.size()-1;
        int ans=binary_search(nums,target,left,right);
        if(ans!=-1) return ans;
        else return -1;
    }
};