class Solution {
public:
    int valid(int mid, vector<int>&nums , int k){
        int cnt = 1 ; 
        int sum = 0 ; 
        
        for(int val : nums){
            if(sum + val <= mid){
                
                sum += val ;
            }
            else{
                sum = val ; 
                 cnt++ ;
            }
        }
        if(cnt > k) return false ;
        return true ;
    }
    int splitArray(vector<int>& nums, int k) {

        int st = 0 ; 
        int end = 0 ; 
        for(int val : nums){
            st = max(st , val) ;
            end += val ; 
        }        
        int ans = 0 ; 
        while(st <= end){
            int mid = st + (end-st)/2 ; 

            if(valid(mid , nums , k)){
                ans = mid ; 
               end = mid-1 ;
                
                            
            }
            else{
                st = mid+1;
            }
        }
        return ans ;
    }
};