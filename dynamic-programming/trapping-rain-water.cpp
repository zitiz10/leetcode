class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();
        if(n==0) return 0;
        vector<int>suffixmax(n);
        suffixmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffixmax[i]=max(suffixmax[i+1],height[i]);
        }
        int total=0;
        int leftmax=height[0];
        for(int i=0;i<n;i++){
            leftmax=max(leftmax,height[i]);
            int rightmax=suffixmax[i];
            if(height[i]<leftmax&&height[i]<rightmax)
            total+=min(leftmax,rightmax)-height[i];
        }
        return total;
    }
};